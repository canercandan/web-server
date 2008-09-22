#include <iostream>
#include "VHost.h"
#include "XmlParser.h"

VHost::VHost()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

VHost::~VHost()
{}

bool	VHost::onLoad()
{
  std::cout << "[mod_vhost] loading..." << std::endl;
  return (true);
}

void	VHost::onUnLoad()
{
  std::cout << "[mod_vhost] unloading..." << std::endl;
}

const VHost::listCallback&	VHost::getCallbacks()
{
  this->_listCallback[ZenZiAPI::PARSED].first =
    static_cast<IModule::p_callback>(&VHost::run);
  this->_listCallback[ZenZiAPI::PARSED].second = ZenZiAPI::FIRST;
  return (this->_listCallback);
}

bool	VHost::run(ZenZiAPI::ITools& tools)
{
  std::cout << "[mod_vhost] running..." << std::endl;

  ZenZiAPI::IRequest*	request = &tools.message().request();
  ZenZiAPI::IConfig*	config = &tools.config();

  std::string	hostname(request->getHeader("Host", "host"));
  std::string	port(request->getHeader("Host", "port"));

  XmlParser	xml(config->getParam("module_directory")
		    + "mod_vhost.xml");

  XmlParser::listParam	list(xml.xmlGetListParam("//vhost"));
  std::string		root;

  for (XmlParser::listParam::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      XmlParser::listAttribute	attr(*it);

      if (attr["hostname"] == hostname &&
	  attr["port"] == port)
	{
	  root = attr["root"];
	  break;
	}
    }

  if (root.empty())
    return (false);

  std::cout << "[mod_vhost] executing" << std::endl;

  request->setHeader("Zia", "document_root", root);
  return (true);
}

extern "C"
{
  EXPORT VHost*	create()
  {
    return (new VHost);
  }

  EXPORT void		destroy(void* p)
  {
    delete static_cast<VHost*>(p);
  }
}
