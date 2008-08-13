//
// ZiaConfiguration.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Wed Aug 13 20:30:30 2008 caner candan
//

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "ZiaConfiguration.h"

ZiaConfiguration*	ZiaConfiguration::_singleton = NULL;

ZiaConfiguration::ZiaConfiguration()
  : _parserXml(NULL)
{
  _map_config["port"] = "80";
}

ZiaConfiguration::~ZiaConfiguration()
{}

ZiaConfiguration*	ZiaConfiguration::getInstance()
{
  if (_singleton == NULL)
    _singleton = new ZiaConfiguration();
  return (_singleton);
}

void			ZiaConfiguration::kill()
{
  if (_singleton != NULL)
    {
      delete (_singleton);
      _singleton = NULL;
    }
}

void	ZiaConfiguration::setParserXml(ParserXml* parserXml)
{
  this->_parserXml = parserXml;
}

ParserXml*	ZiaConfiguration::getParserXml()
{
  return (this->_parserXml);
}

void	ZiaConfiguration::setValue(const std::string& key,
				   const std::string& val)
{
  this->_map_config[key] = val;
}

const std::string&	ZiaConfiguration::getValue(const std::string& key)
{
  return (this->_map_config[key]);
}

void	ZiaConfiguration::loadConfig()
{
  if (this->_parserXml)
    {
      int		time = ::time(NULL);
      std::stringstream	ss;

      ss << time;
      this->setValue("name", this->_parserXml->xmlGetValue("/server[@name]"));
      this->setValue("port", this->_parserXml->xmlGetValue("/server/config/port[@value]"));
      this->setValue("shutdown", this->_parserXml->xmlGetValue("/server/config/shutdown[@value]"));
      this->setValue("debug", this->_parserXml->xmlGetValue("/server/config/debug[@value]"));
      this->setValue("respect_rfc", this->_parserXml->xmlGetValue("/server/config/respect_rfc[@value]"));
      this->setValue("document_root", this->_parserXml->xmlGetValue("/server/config/document_root[@value]"));
      this->setValue("timestart", ss.str());
    }
}

void	ZiaConfiguration::ziaDumpConfig()
{
  mapConfig::const_iterator	it;
  mapConfig::const_iterator	end = this->_map_config.end();

  for (it = this->_map_config.begin(); it != end; ++it)
    std::cout << it->first << std::endl;
}
