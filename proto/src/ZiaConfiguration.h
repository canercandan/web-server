/*
** ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Jul 31 22:13:58 2008 majdi toumi
** Last update Mon Aug  4 18:32:04 2008 majdi toumi
*/

#ifndef _ZIACONFIGURATION_H__
# define __ZIACONFIGURATION_H__

#include <string>
#include <list>

class			ZiaConfiguration
{
 private:
  std::string		_name;
  int			_port;
  std::string		_shutdown;
  bool			_debug;
  bool			_respect_rfc;

 public:
  ZiaConfiguration();
  ZiaConfiguration(const ZiaConfiguration& ziaConfig);
  ZiaConfiguration&	operator=(const ZiaConfiguration& ziaConfig);

  void			setName(std::string name);
  void			setPort(int port);
  void			setShutdown(std::string shutdown);
  void			setDebug(bool debug);
  void			setRespectRfc(bool respect_rfc);

  std::string		getName();
  int			getPort();
  std::string		getShutdown();
  bool			getDebug();
  bool			getRespectRfc();
};

#endif /* !__ZIACONFIGURATION_H__ */
