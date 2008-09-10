//
// Config.cpp for **zia** in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 11:30:03 2008 majdi toumi
// Last update Tue Sep  9 20:46:39 2008 majdi toumi
//

#include <iostream>
#include <sstream>
#include "Config.h"

using namespace ZenZiAPI;

Config::Config()
  : _xmlParser(new XmlParser(CONFIG_FILE))
{
  setParam("port", "80");
  _loadConfig();
}

std::string&	Config::getParam(const std::string& param)
{
  return (this->_map_config[param]);
}

int		Config::getParamInt(const std::string& param)
{
  std::stringstream	ss(this->_map_config[param]);
  int			res;

  ss >> res;
  return (res);
}

IConfig::OS	Config::getOS()
{
#ifdef WIN32
  return (IConfig::WINDOWS);
#elifdef LINUX
  return (IConfig::LINUX);
#elifdef MAX_OS
  return (IConfig::MAC_OS);
#elifdef BSD
  return (IConfig::BSD);
#else
  return (IConfig::OTHER);
#endif
}

void		Config::_loadConfig()
{
  const time_t& time = ::time(NULL);
  std::stringstream	ss;

  ss << time;
  this->setXmlParam("name", "/server[@name]");
  this->setXmlParam("port", "/server/config/port[@value]");
  this->setXmlParam("shutdown", "/server/config/shutdown[@value]");
  this->setXmlParam("debug", "/server/config/debug[@value]");
  this->setXmlParam("respect_rfc", "/server/config/respect_rfc[@value]");
  this->setXmlParam("document_root", "/server/config/document_root[@value]");
  this->setXmlParam("module_directory", "/server/config/module_directory[@value]");
  this->setXmlParam("timeout", "/server/config/timeout[@value]");
  this->setParam("timestart", ss.str());
  this->getListModule();
}

void		Config::setParam(const std::string& key,
			 const std::string& value)
{
  this->_map_config[key] = value;
}

void		Config::setXmlParam(const std::string& key,
			    const std::string& path)
{
  this->setParam(key, this->_xmlParser->xmlGetParam(path));
}

Config::ListModule_t&	Config::getListModule()
{
  FileInfo	info(this->_map_config["module_directory"]);
  std::string	time;

  time = info.getLastTimeAccess();
  if ((this->_last_access == "") || (this->_last_access != time))
    {
      this->refresh(info);
      this->_last_access = time;
    }
  return (this->_list_module);
}

void	Config::refresh(FileInfo& info)
{
  IFileInfo::listDir	dir = info.getListDir();
  IFileInfo::listDir::const_iterator	itb;
  IFileInfo::listDir::const_iterator	ite = dir.end();
  int			found;

  this->_list_module.clear();
  for (itb = dir.begin(); itb != ite; itb++)
    {
      found = itb->find_last_of(".");
#ifdef WIN32
      if (itb->substr(found + 1) == "dll")
#else
	if (itb->substr(found + 1) == "so")
#endif
	  this->_list_module.push_back(this->_map_config["module_directory"] + *itb);
    }
}

void		Config::ziaDumpConfig()
{
//   MapConfig_t::const_iterator	it;
//   MapConfig_t::const_iterator	end = this->_map_config.end();

//   for (it = this->_map_config.begin(); it != end; ++it)
//     std::cout << it->first << ":" << it->second << std::endl;

  std::list<std::string>::const_iterator	itb;
  std::list<std::string>::const_iterator	ite = this->_list_module.end();

  std::cout << "liste module: " << std::endl;
  for (itb = this->_list_module.begin(); itb != ite; itb++)
    std::cout << *itb << std::endl;
  std::cout << std::endl;
}
