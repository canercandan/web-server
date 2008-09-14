//
// Config.cpp for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 11:30:03 2008 majdi toumi
// Last update Thu Sep 11 18:24:07 2008 caner candan
//

#include <iostream>
#include <sstream>
#include <time.h>
#include "Config.h"

Config::Config()
  : _xmlParser(new XmlParser(CONFIG_FILENAME))
{
  _setParam("port", "80");
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

  this->_setXmlParam("name", "/server[@name]");
  this->_setXmlParam("port", "/server/config/port[@value]");
  this->_setXmlParam("shutdown", "/server/config/shutdown[@value]");
  this->_setXmlParam("debug", "/server/config/debug[@value]");
  this->_setXmlParam("respect_rfc", "/server/config/respect_rfc[@value]");
  this->_setXmlParam("document_root", "/server/config/document_root[@value]");
  this->_setXmlParam("module_directory", "/server/config/module_directory[@value]");
  this->_setXmlParam("timeout", "/server/config/timeout[@value]");
  ss << time;
  this->_setParam("timestart", ss.str());
}

void	Config::_setParam(const std::string& key,
			  const std::string& value)
{
  this->_mapConfig[key] = value;
}

void	Config::_setXmlParam(const std::string& key,
			     const std::string& path)
{
  this->_setParam(key, this->_xmlParser->xmlGetParam(path));
}
