#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
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
  this->getListModule();
  this->getListModule();
}

const std::list<std::string>&	Config::getListModule()
{
  struct stat	st;
  char		*time;

  if (lstat(this->_mapConfig["module_directory"].c_str(), &st) == -1)
    std::cerr << "Can't access module directory stat" << std::endl;
  else
    {
      time = ctime(&st.st_ctime);
      if ((this->_last_update == "") || strcmp(time, this->_last_update.c_str()))
	{
	  this->refresh();
	  this->_last_update = time;
	}
    }
  return (this->_listModule);
}

void	Config::refresh()
{
  DIR		*dir;
  struct dirent	*sd;
  int		found;

  this->_listModule.clear();
  dir = opendir(this->_mapConfig["module_directory"].c_str());
  if (dir == NULL)
    std::cerr << "Can't find module directory" << std::endl;
  else
    {
      while ((sd = readdir(dir)) != NULL)
	{
	  std::string file(sd->d_name);
	  found = file.find_last_of(".");
	  if ((file != ".") && (file != "..") && (file.substr(found + 1) == "so"))
	    this->_listModule.push_back(this->_mapConfig["module_directory"] + file);
	}
    }
}

void	Config::ziaDumpConfig()
{
  mapConfig::const_iterator	it;
  mapConfig::const_iterator	end = this->_mapConfig.end();

  for (it = this->_mapConfig.begin(); it != end; ++it)
    std::cout << it->first << std::endl;

  std::list<std::string>::const_iterator	itb;
  std::list<std::string>::const_iterator	ite = this->_listModule.end();

  std::cout << "liste module" << std::endl;
  for (itb = this->_listModule.begin(); itb != ite; itb++)
    std::cout << *itb << std::endl;
  std::cout << std::endl;
}
