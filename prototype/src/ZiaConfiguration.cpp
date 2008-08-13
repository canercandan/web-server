//
// ZiaConfiguration.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Tue Aug 12 07:10:54 2008 florent hochwelker
//

#include <iostream>
#include <sstream>
#include <string>
#include "ZiaConfiguration.h"

ZiaConfiguration*		ZiaConfiguration::_singleton = NULL;

ZiaConfiguration::ZiaConfiguration()
{
  _map_config["port"] = "80";
}

ZiaConfiguration::~ZiaConfiguration()
{
}

ZiaConfiguration*	ZiaConfiguration::getInstance()
{
  if (_singleton == NULL)
    {
      _singleton = new ZiaConfiguration();
    }
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

  //   std::cout << " ->> Dump zia configuration:"
  // 	    << std::endl
  // 	    << "Name = " << this->_map_config["name"]
  // 	    << std::endl
  // 	    << "Port = " << this->_map_config["port"]
  // 	    << std::endl
  // 	    << "Shutdown = " << this->_map_config["shutdown"]
  // 	    << std::endl
  // 	    << "Debug = " << this->_map_config["debug"]
  // 	    << std::endl
  // 	    << "Respect rfc = " << this->_map_config["respect_rfc"]
  // 	    << std::endl
  // 	    << "Document root = " << this->_map_config["document_root"]
  // 	    << std::endl;
  std::map<std::string, std::string>::iterator	it;
  for (it = this->_map_config.begin(); it != this->_map_config.end(); ++it)
    {
      std::cout << it->first << std::endl;
    }
}
