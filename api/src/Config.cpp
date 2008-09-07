#ifndef WIN32
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
# else
#endif
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "Config.h"
#include "FileInfo.h"

using namespace	ziApi;

Config::Config()
  : _xmlParser(new XmlParser(FILE_CONFIG))
{
  setValue("port", "80");
  _loadConfig();
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
  this->getListModule();
}

const std::list<std::string>&	Config::getListModule()
{
  FileInfo	info(this->_mapConfig["module_directory"]);
  std::string	time;

  time = info.getLastTimeAccess();
  if ((this->_last_access == "") || (this->_last_access != time))
    {
      this->refresh(info);
      this->_last_access = time;
    }
  return (this->_listModule);
}

void	Config::refresh(FileInfo& info)
{
  IFileInfo::listDir	dir = info.getListDir();
  IFileInfo::listDir::const_iterator	itb;
  IFileInfo::listDir::const_iterator	ite = dir.end();
  int			found;

  this->_listModule.clear();
  for (itb = dir.begin(); itb != ite; itb++)
    {
      found = itb->find_last_of(".");
#ifdef WIN32
      if (itb->substr(found + 1) == "dll")
#else
	if (itb->substr(found + 1) == "so")
#endif
	  this->_listModule.push_back(this->_mapConfig["module_directory"] + *itb);
    }
}

void	Config::ziaDumpConfig()
{
//   mapConfig::const_iterator	it;
//   mapConfig::const_iterator	end = this->_mapConfig.end();

//   for (it = this->_mapConfig.begin(); it != end; ++it)
//     std::cout << it->first << std::endl;

  std::list<std::string>::const_iterator	itb;
  std::list<std::string>::const_iterator	ite = this->_listModule.end();

  std::cout << "liste module: " << std::endl;
  for (itb = this->_listModule.begin(); itb != ite; itb++)
    std::cout << *itb << std::endl;
  std::cout << std::endl;
}
