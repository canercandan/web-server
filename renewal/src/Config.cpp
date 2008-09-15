//
// Config.cpp for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 11:30:03 2008 majdi toumi
// Last update Mon Sep 15 15:26:33 2008 majdi toumi
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

XmlParser::ListParam_t	Config::getListParam(const std::string& param)
{
  return (this->_xmlParser->xmlGetListParam(param));
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
  this->_setXmlParam("port", "/server/default_port[@value]");
  this->_setXmlParam("shutdown", "/server/shutdown[@value]");
  this->_setXmlParam("debug", "/server/debug[@value]");
  this->_setXmlParam("respect_rfc", "/server/respect_rfc[@value]");
  this->_setXmlParam("document_root", "/server/document_root[@value]");
  this->_setXmlParam("module_directory", "/server/module_directory[@value]");
  this->_setXmlParam("file_404", "/server/file_404[@value]");
  this->_setXmlParam("timeout", "/server/timeout[@value]");
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
