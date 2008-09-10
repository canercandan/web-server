//
// Config.h for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon Sep  8 13:45:46 2008 majdi toumi
// Last update Wed Sep 10 18:04:27 2008 caner candan
//

#ifndef __CONFIG_H__
# define __CONFIG_H__

#include <string>
#include <map>
#include "IConfig.hpp"
#include "XmlParser.h"
#include "FileInfo.h"
#include "Singleton.hpp"

# define CONFIG_FILENAME	"../server.xml"

class	Config : public ZenZiAPI::IConfig, public Singleton<Config>
{
public:
  typedef std::map<std::string, std::string>	mapConfig;
public:
  Config();

  std::string&	getParam(const std::string& param);
  int		getParamInt(const std::string& param);

  OS		getOS();

  //listModule&	getListModule();
  void		refresh(FileInfo& info);
  void		ziaDumpConfig();
private:
  void	_loadConfig();
  void	_setParam(const std::string& key,
		  const std::string& value);
  void	_setXmlParam(const std::string& key,
		     const std::string& path);
private:
  mapConfig			_map_config;
  listModule			_list_module;
  std::string			_last_access;
  std::auto_ptr<XmlParser>	_xmlParser;
};

#endif /*! __CONFIG_H__ */
