//
// ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:13:58 2008 majdi toumi
// Last update Tue Aug 12 16:11:19 2008 majdi toumi
//

#ifndef __ZIACONFIGURATION_H__
# define __ZIACONFIGURATION_H__

#include <iostream>
#include <string>
#include <list>
#include <map>

class					ZiaConfiguration
{
 public:
  ZiaConfiguration();
  ZiaConfiguration(const ZiaConfiguration& ziaConfig);
  ZiaConfiguration&			operator=(const ZiaConfiguration& ziaConfig);

  void					generateMapResponse();
  void					setName(std::string name);
  void					setPort(unsigned int port);
  void					setShutdown(std::string shutdown);
  void					setDebug(bool debug);
  void					setRespectRfc(std::string respect_rfc);
  void					setDocumentRoot(std::string document_root);
  void					ziaDumpConfig();

  const std::string			getName() const;
  const unsigned int			getPort() const;
  const std::string			getShutdown() const;
  const bool				getDebug() const;
  const std::string			getRespectRfc() const;
  const std::string			getDocumentRoot() const;

 private:
  std::string				_name;
  unsigned int				_port;
  std::string				_shutdown;
  bool					_debug;
  std::string				_respect_rfc;
  std::string				_document_root;
  std::map<std::string, std::string>	_map_response;
};

#endif /* !__ZIACONFIGURATION_H__ */
