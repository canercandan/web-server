#ifdef WIN32
#else
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#endif

#include <iostream>
#include "CgiBin.h"
#include "FluxString.h"
#include "Consumer.h"
#include "URIParser.h"
#include "XmlParser.h"

CgiBin::CgiBin()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

CgiBin::~CgiBin()
{}

bool	CgiBin::onLoad()
{
  std::cout << "[mod_cgibin] loading..." << std::endl;
  return (true);
}

void	CgiBin::onUnLoad()
{
  std::cout << "[mod_cgibin] unloading..." << std::endl;
}

const CgiBin::listCallback&	CgiBin::getCallbacks()
{
  this->_listCallback[ZenZiAPI::FILESYSTEM].first =
    static_cast<IModule::p_callback>(&CgiBin::run);
  this->_listCallback[ZenZiAPI::FILESYSTEM].second = ZenZiAPI::FIRST;
  return (this->_listCallback);
}

bool	CgiBin::run(ZenZiAPI::ITools& tools)
{
  std::cout << "[mod_cgibin] running..." << std::endl;

  ZenZiAPI::IRequest*	request = &tools.message().request();
  ZenZiAPI::IConfig*	config = &tools.config();
  FluxString		flux(request->getUri());
  Consumer		consumer(flux);
  URIParser		uri(consumer);

  uri.run();

  const std::string&	path = uri.getPath();
  size_t		pos;

  if ((pos = path.find_last_of('.')) == std::string::npos)
    return (false);

  std::string	ext(path.substr(pos + 1));

  XmlParser	xml(config->getParam("module_directory")
		    + "mod_cgibin.xml");
  std::string	env(xml.xmlGetParam("/cgibin", "env"));

  XmlParser::listParam	list(xml.xmlGetListParam("//cgibin"));
  std::string		bin;

  for (XmlParser::listParam::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      XmlParser::listAttribute&	attr = *it;

      if (!ext.compare(attr["ext"]))
	{
	  bin = attr["bin"];
	  break;
	}
    }

  if (bin.empty())
    return (false);

  std::string	app(config->getParam("document_root") + path);

  std::cout << "[mod_cgibin] executing " << app << std::endl;

#ifdef WIN32
  std::cout << "Not yet implemented."<< std::endl;
  return (false);
#else
  pid_t	pid;
  int	pip[2];
  char	buff[8193];
  int	count;

  ::pipe(pip);
  if (!(pid = ::fork()))
    {
      size_t		pos = env.find_last_of('/');
      std::string	binEnv(env.substr(pos + 1));

      ::close(pip[0]);
      ::dup2(pip[1], 1);
      ::execl(env.c_str(), binEnv.c_str(),
	      bin.c_str(), app.c_str(), (char*)0);
      ::close(pip[1]);
    }
  else
    {
      ::close(pip[1]);
      ::wait(NULL);
      request->bodyAppend(std::string("HTTP/1.1 200 OK\r\n"));
      while((count = ::read(pip[0], buff, 8192)) > 0)
	{
	  buff[count] = 0;
	  request->bodyAppend(buff);
	}
    }
  return (true);
#endif
}

extern "C"
{
  EXPORT CgiBin*	create()
  {
    return (new CgiBin);
  }

  EXPORT void		destroy(void* p)
  {
    delete static_cast<CgiBin*>(p);
  }
}
