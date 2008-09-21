//
// Config.cpp for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 11:30:03 2008 majdi toumi
// Last update Sun Sep 21 11:40:14 2008 caner candan
//

#include <iostream>
#include <sstream>
#include <time.h>
#include "Config.h"

Config::Config()
  : _xmlParser(CONFIG_FILE)
{
  setParam("port", "80");
  _loadConfig();
}

std::string&	Config::getParam(const std::string& param)
{
  return (this->_mapConfig[param]);
}

int		Config::getParamInt(const std::string& param)
{
  std::stringstream	ss(this->_mapConfig[param]);
  int			res;

  ss >> res;
  return (res);
}

XmlParser::listParam	Config::getListParam(const std::string& param)
{
  return (this->_xmlParser.xmlGetListParam(param));
}

Config::OS	Config::getOS()
{
#if defined(WIN32)
  return (IConfig::WINDOWS);
#elif defined(LINUX)
  return (IConfig::LINUX);
#elif defined(__APPLE__)
  return (IConfig::MAC_OS);
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
  return (IConfig::BSD);
#else
  return (IConfig::OTHER);
#endif
}

void	Config::_loadConfig()
{
  const time_t&		time = ::time(NULL);
  std::stringstream	ss;

  this->setXmlParam("name", "/server", "name");
  this->setXmlParam("port", "/server/default_port", "value");
  this->setXmlParam("shutdown", "/server/shutdown", "value");
  this->setXmlParam("debug", "/server/debug", "value");
  this->setXmlParam("document_root", "/server/document_root", "value");
  this->setXmlParam("module_directory", "/server/module_directory", "value");
  this->setXmlParam("file_404", "/server/file_404", "value");
  this->setXmlParam("timeout", "/server/timeout", "value");
  ss << time;
  this->setParam("timestart", ss.str());
}

void	Config::setParam(const std::string& key,
			 const std::string& value)
{
  this->_mapLastConfig[key] = this->_mapConfig[key];
  this->_mapConfig[key] = value;
}

void	Config::setLastParam(const std::string& key)
{
  this->_mapConfig[key] = this->_mapLastConfig[key];
}

void	Config::setXmlParam(const std::string& key,
			    const std::string& path,
			    const std::string& attr)
{
  this->setParam(key, this->_xmlParser.xmlGetParam(path, attr));
}
