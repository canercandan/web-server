//
// Config.h for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon Sep  8 13:45:46 2008 majdi toumi
// Last update Wed Sep 10 16:03:07 2008 majdi toumi
//

#ifndef __CONFIG_H__
# define __CONFIG_H__

#include <string>
#include <map>
#include <list>
#include "IConfig.hpp"
#include "XmlParser.h"
#include "FileInfo.h"
#include "Singleton.hpp"

# define CONFIG_FILENAME	"../server.xml"

class	Config : public ZenZiAPI::IConfig, public Singleton<Config>
{
public:
  typedef std::map<std::string, std::string>	MapConfig_t;
  typedef std::list<std::string>		ListModule_t;

public:
  Config();

  std::string&	getParam(const std::string& param);
  int		getParamInt(const std::string& param);

  OS		getOS();

  ListModule_t&	getListModule();
  void		refresh(FileInfo& info);
  void		ziaDumpConfig();

private:
  void	loadConfig();
  void	setParam(const std::string& key, const std::string& value);
  void	setXmlParam(const std::string& key, const std::string& path);

private:
  MapConfig_t			_map_config;
  ListModule_t			_list_module;
  std::string			_last_access;
  std::auto_ptr<XmlParser>	_xmlParser;
};

#endif /*! __CONFIG_H__ */
