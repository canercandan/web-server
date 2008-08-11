//
// ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:13:58 2008 majdi toumi
// Last update Mon Aug 11 20:16:45 2008 majdi toumi
//

#ifndef __ZIACONFIGURATION_H__
# define __ZIACONFIGURATION_H__

#include <iostream>
#include <string>
#include <list>

class			ZiaConfiguration
{
 public:
  ZiaConfiguration();
  ZiaConfiguration(const ZiaConfiguration& ziaConfig);
  ZiaConfiguration&	operator=(const ZiaConfiguration& ziaConfig);

  void			setName(std::string name);
  void			setPort(int port);
  void			setShutdown(std::string shutdown);
  void			setDebug(bool debug);
  void			setRespectRfc(std::string respect_rfc);
  void			setDocumentRoot(std::string document_root);
  void			ziaDumpConfig();

  std::string		getName();
  int			getPort();
  std::string		getShutdown();
  bool			getDebug();
  std::string		getRespectRfc();
  std::string		getDocumentRoot();

 private:
  std::string		_name;
  int			_port;
  std::string		_shutdown;
  bool			_debug;
  std::string		_respect_rfc;
  std::string		_document_root;
};

#endif /* !__ZIACONFIGURATION_H__ */
