//
// ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:13:58 2008 majdi toumi
// Last update Wed Aug 13 18:50:20 2008 majdi toumi
//

#ifndef __ZIACONFIGURATION_H__
# define __ZIACONFIGURATION_H__

#include <iostream>
#include <string>
#include <list>
#include <map>

class				ZiaConfiguration
{
 public:
  static ZiaConfiguration*	getInstance();
  static void			kill();
  void				setValue(std::string key, std::string val);
  std::string			getValue(std::string key);
  void				ziaDumpConfig();

 private:
  ZiaConfiguration();
  ~ZiaConfiguration();

  static ZiaConfiguration		*_singleton;
  std::map<std::string, std::string>	_map_config;
};

#endif /* !__ZIACONFIGURATION_H__ */
