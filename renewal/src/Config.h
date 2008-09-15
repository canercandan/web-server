//
// Config.h for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon Sep  8 13:45:46 2008 majdi toumi
// Last update Mon Sep 15 12:02:37 2008 majdi toumi
//

#ifndef __CONFIG_H__
# define __CONFIG_H__

#include <string>
#include <map>
#include "IConfig.hpp"
#include "XmlParser.h"
#include "Singleton.hpp"

# define CONFIG_FILENAME	"../server.xml"

class	Config : public ZenZiAPI::IConfig, public Singleton<Config>
{
  friend class	Singleton<Config>;
public:
  typedef std::map<std::string, std::string>	mapConfig;

public:
  std::string&			getParam(const std::string& param);
  int				getParamInt(const std::string& param);
  XmlParser::ListParam_t	getListParam(const std::string& param);
  OS				getOS();

private:
  Config();

  void	_loadConfig();
  void	_setParam(const std::string& key, const std::string& value);
  void	_setXmlParam(const std::string& key, const std::string& path);
private:
  mapConfig			_mapConfig;
  std::auto_ptr<XmlParser>	_xmlParser;
};

#endif /*! __CONFIG_H__ */
