#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "Config.h"

Config::Config()
  : _xml_parser(new XmlParser)
{
  _map_config["port"] = "80";
}

void	Config::setXmlParser(XmlParser* xmlParser)
{
  this->_xml_parser = xmlParser;
}

XmlParser*	Config::getXmlParser()
{
  return (this->_xml_parser);
}

void	Config::setValue(const std::string& key,
			 const std::string& val)
{
  this->_map_config[key] = val;
}

const std::string&	Config::getValue(const std::string& key)
{
  return (this->_map_config[key]);
}

void	Config::loadConfig()
{
  if (this->_xml_parser)
    {
      const time_t& time = ::time(NULL);
      std::stringstream	ss;

      ss << time;
      this->setValue("name", this->_xml_parser->xmlGetValue("/server[@name]"));
      this->setValue("port", this->_xml_parser->xmlGetValue("/server/config/port[@value]"));
      this->setValue("shutdown", this->_xml_parser->xmlGetValue("/server/config/shutdown[@value]"));
      this->setValue("debug", this->_xml_parser->xmlGetValue("/server/config/debug[@value]"));
      this->setValue("respect_rfc", this->_xml_parser->xmlGetValue("/server/config/respect_rfc[@value]"));
      this->setValue("document_root", this->_xml_parser->xmlGetValue("/server/config/document_root[@value]"));
      this->setValue("module_directory", this->_xml_parser->xmlGetValue("/server/config/module_directory[@value]"));
      this->setValue("timestart", ss.str());
      this->getListModule();
    }
}

void	Config::getListModule()
{
}

void	Config::ziaDumpConfig()
{
  mapConfig::const_iterator	it;
  mapConfig::const_iterator	end = this->_map_config.end();

  for (it = this->_map_config.begin(); it != end; ++it)
    std::cout << it->first << std::endl;
}
