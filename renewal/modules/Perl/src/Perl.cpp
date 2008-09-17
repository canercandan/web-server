#ifdef WIN32
#else
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#endif

#include <iostream>
#include "Perl.h"
#include "FluxString.h"
#include "Consumer.h"
#include "URIParser.h"

Perl::Perl()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

Perl::~Perl()
{}

bool	Perl::onLoad()
{
  std::cout << "Perl loading..." << std::endl;
  return (true);
}

void	Perl::onUnLoad()
{
  std::cout << "Perl unloading..." << std::endl;
}

const Perl::listCallback&	Perl::getCallbacks()
{
  this->_listCallback[ZenZiAPI::FILESYSTEM].first =
    static_cast<IModule::p_callback>(&Perl::run);
  this->_listCallback[ZenZiAPI::FILESYSTEM].second = ZenZiAPI::FIRST;
  return (this->_listCallback);
}

bool	Perl::run(ZenZiAPI::ITools& tools)
{
  std::cout << "Perl is running..." << std::endl;

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

  std::string	ext(path.substr(pos));

  if (ext.compare(".pl"))
    return (false);

  std::string	app(config->getParam("document_root") + path);

  std::cout << "[mod_perl] executing " << app << std::endl;

#ifdef WIN32
  std::cout << "Not yet implemented."<< std::endl;
  return (false);
#else
  pid_t		pid;
  int		pip[2];
  char		buff[8193];
  int		count;

  ::pipe(pip);
  if ((pid = ::fork()) < 0)
    std::cout << "fork failed, mamamia !"<< std::endl;
  if (pid == 0)
    {
      ::close(pip[0]);
      ::dup2(pip[1], 1);
      ::execl("/usr/bin/perl", "perl", app.c_str(), (char*)0);
      ::close(pip[1]);
    }
  else
    {
      close(pip[1]);
      ::wait(NULL);

      std::string*	response = new std::string;

      while((count = ::read(pip[0], buff, 8192)) > 0)
	{
	  buff[count] = 0;
	  response->append(buff);
	}
      tools.data(response);
    }
  return (true);
#endif
}

extern "C"
{
  EXPORT Perl*	create()
  {
    return (new Perl);
  }

  EXPORT void		destroy(void* p)
  {
    delete static_cast<Perl*>(p);
  }
}
