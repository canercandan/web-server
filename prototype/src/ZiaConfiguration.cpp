//
// ZiaConfiguration.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Wed Aug 13 00:42:37 2008 majdi toumi
//

#include <iostream>
#include <sstream>
#include <string>
#include "ZiaConfiguration.h"

ZiaConfiguration::ZiaConfiguration()
{
  _map_config["port"] = 80;
}

ZiaConfiguration::ZiaConfiguration(const ZiaConfiguration& ziaConfig)
{
  *this = ziaConfig;
}

ZiaConfiguration&	ZiaConfiguration::operator=(const ZiaConfiguration& ziaConfig)
{
  if (this != &ziaConfig)
    this->_map_config = ziaConfig._map_config;
  return (*this);
}

void			ZiaConfiguration::setValue(std::string key, std::string val)
{
  this->_map_config[key] = val;
}

std::string		ZiaConfiguration::getValue(std::string key)
{
  return (this->_map_config[key]);
}

void			ZiaConfiguration::ziaDumpConfig()
{
  std::cout << " ->> Dump zia configuration:"
	    << std::endl
	    << "Name = " << this->_map_config["name"]
	    << std::endl
	    << "Port = " << this->_map_config["port"]
	    << std::endl
	    << "Shutdown = " << this->_map_config["shutdown"]
	    << std::endl
	    << "Debug = " << this->_map_config["debug"]
	    << std::endl
	    << "Respect rfc = " << this->_map_config["respect_rfc"]
	    << std::endl
	    << "Document root = " << this->_map_config["document_root"]
	    << std::endl;
}
