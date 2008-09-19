#include <iostream>
#include "Mime.h"
#include "FluxString.h"
#include "Consumer.h"
#include "URIParser.h"
#include "XmlParser.h"

Mime::Mime()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

Mime::~Mime()
{}

bool	Mime::onLoad()
{
  std::cout << "[mod_mime] loading..." << std::endl;
  return (true);
}

void	Mime::onUnLoad()
{
  std::cout << "[mod_mime] unloading..." << std::endl;
}

const Mime::listCallback&	Mime::getCallbacks()
{
  this->_listCallback[ZenZiAPI::FILESYSTEM].first =
    static_cast<IModule::p_callback>(&Mime::run);
  this->_listCallback[ZenZiAPI::FILESYSTEM].second = ZenZiAPI::FIRST;
  return (this->_listCallback);
}

bool	Mime::run(ZenZiAPI::ITools& tools)
{
  std::cout << "[mod_mime] running..." << std::endl;

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

  std::cout << "debug: [" << ext << ']' << std::endl;

  XmlParser	xml(config->getParam("module_directory")
		    + "mod_mime.xml");

  XmlParser::listParam	list(xml.xmlGetListParam("//mime"));
  std::string		content;

  for (XmlParser::listParam::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      XmlParser::listAttribute&	attr = *it;

      if (!ext.compare(attr["ext"]))
	{
	  content = attr["content"];
	  break;
	}
    }

  if (content.empty())
    return (false);

  std::cout << "debug: [" << content << ']' << std::endl;
  std::cout << "[mod_mime] executing " << std::endl;

  request->setChunk(true);
  return (true);
}

extern "C"
{
  EXPORT Mime*	create()
  {
    return (new Mime);
  }

  EXPORT void		destroy(void* p)
  {
    delete static_cast<Mime*>(p);
  }
}
