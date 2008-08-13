//
// ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:13:58 2008 majdi toumi
// Last update Wed Aug 13 20:06:37 2008 caner candan
//

#ifndef __ZIACONFIGURATION_H__
# define __ZIACONFIGURATION_H__

#include <iostream>
#include <string>
#include <list>
#include <map>
#include "ParserXml.h"

class	ZiaConfiguration
{
  typedef std::map<std::string, std::string>	mapConfig;

 public:
  static ZiaConfiguration*	getInstance();
  static void			kill();

  void		setParserXml(ParserXml*);
  ParserXml*	getParserXml();

  void			setValue(const std::string& key,
				 const std::string& val);
  const std::string&	getValue(const std::string& key);

  void	loadConfig();
  void	ziaDumpConfig();
 private:
  ZiaConfiguration();
  ~ZiaConfiguration();

  static ZiaConfiguration*	_singleton;
  mapConfig			_map_config;
  ParserXml*			_parserXml;
};

#endif // !__ZIACONFIGURATION_H__
