#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "Config.h"

using namespace	ziApi;

Config::Config()
  : _xmlParser(new XmlParser(FILE_CONFIG))
{
  setValue("port", "80");
  _loadConfig();
}

Config::~Config()
{
  delete _xmlParser;
}

void	Config::setValue(const std::string& key,
			 const std::string& value)
{
  this->_mapConfig[key] = value;
}

void	Config::setXmlValue(const std::string& key,
			    const std::string& path)
{
  this->setValue(key, this->_xmlParser->xmlGetValue(path));
}

const std::string&	Config::getValue(const std::string& key)
{
  return (this->_mapConfig[key]);
}

void	Config::_loadConfig()
{
  const time_t& time = ::time(NULL);
  std::stringstream	ss;

  ss << time;
  this->setXmlValue("name", "/server[@name]");
  this->setXmlValue("port", "/server/config/port[@value]");
  this->setXmlValue("shutdown", "/server/config/shutdown[@value]");
  this->setXmlValue("debug", "/server/config/debug[@value]");
  this->setXmlValue("respect_rfc", "/server/config/respect_rfc[@value]");
  this->setXmlValue("document_root", "/server/config/document_root[@value]");
  this->setXmlValue("module_directory", "/server/config/module_directory[@value]");
  this->setXmlValue("timeout", "/server/config/timeout[@value]");
  this->setValue("timestart", ss.str());
}

const Config::listModule&	Config::getListModule()
{
  this->_xmlParser->refresh();
  this->_listModule.clear();
  this->_listModule.push_back("../modules/mod_autoindex.so");
  this->_listModule.push_back("../modules/mod_perl.so");
  return (this->_listModule);
}

void	Config::ziaDumpConfig()
{
  mapConfig::const_iterator	it;
  mapConfig::const_iterator	end = this->_mapConfig.end();

  for (it = this->_mapConfig.begin(); it != end; ++it)
    std::cout << it->first << std::endl;
}
