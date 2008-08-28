#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "Config.h"

Config::Config()
  : _xmlParser(new XmlParser)
{
  _mapConfig["port"] = "80";
}

void	Config::setXmlParser(XmlParser* xmlParser)
{
  this->_xmlParser = xmlParser;
}

XmlParser*	Config::getXmlParser()
{
  return (this->_xmlParser);
}

void	Config::setValue(const std::string& key,
			 const std::string& val)
{
  this->_mapConfig[key] = val;
}

const std::string&	Config::getValue(const std::string& key)
{
  return (this->_mapConfig[key]);
}

void	Config::_loadConfig()
{
  if (this->_xmlParser)
    {
      const time_t& time = ::time(NULL);
      std::stringstream	ss;

      ss << time;
      this->setValue("name", this->_xmlParser->xmlGetValue("/server[@name]"));
      this->setValue("port", this->_xmlParser->xmlGetValue("/server/config/port[@value]"));
      this->setValue("shutdown", this->_xmlParser->xmlGetValue("/server/config/shutdown[@value]"));
      this->setValue("debug", this->_xmlParser->xmlGetValue("/server/config/debug[@value]"));
      this->setValue("respect_rfc", this->_xmlParser->xmlGetValue("/server/config/respect_rfc[@value]"));
      this->setValue("document_root", this->_xmlParser->xmlGetValue("/server/config/document_root[@value]"));
      this->setValue("timestart", ss.str());
    }
}

void	Config::ziaDumpConfig()
{
  mapConfig::const_iterator	it;
  mapConfig::const_iterator	end = this->_mapConfig.end();

  for (it = this->_mapConfig.begin(); it != end; ++it)
    std::cout << it->first << std::endl;
}
