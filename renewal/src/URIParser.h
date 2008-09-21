//
// URIParser.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Fri Sep 12 15:33:26 2008 caner candan
// Last update Sun Sep 21 03:03:29 2008 caner candan
//

#ifndef __URIPARSER_H__
# define __URIPARSER_H__

# include <string>
# include "IParser.h"
# include "Consumer.h"

class	URIParser : public IParser
{
public:
  URIParser(Consumer& consumer);

  bool	run();
public:
  const std::string&	getHost(void){return (_host);}
private:
  void	_setHost(const std::string& host){_host = host;}
private:
  std::string	_host;

public:
  const std::string&	getPort(void){return (_port);}
private:
  void	_setPort(const std::string& port){_port = port;}
private:
  std::string	_port;

public:
  const std::string&	getPath(void){return (_path);}
private:
  void	_setPath(const std::string& path){_path = path;}
private:
  std::string	_path;

public:
  const std::string&	getQuery(void){return (_query);}
private:
  void	_setQuery(const std::string& query){_query = query;}
private:
  std::string	_query;
private:
  bool	_readHierPart();
  bool	_readAbsoluteURI();
  bool	_readScheme();
  bool	_readAuthority();
  bool	_readUserInfo();

  bool	_readHost();
  bool	_readPort();

  bool	_readIPLiteral();
  bool	_readIPvFuture();
  bool	_readIPv6address();
  bool	_readIPv4address();

  bool	_readDecOctet();
  bool	_readRegName();

  bool	_readPath();
  bool	_readPathAbempty();
  bool	_readPathAbsolute();
  bool	_readPathAbsoluteQuery();
  bool	_readPathNoScheme();
  bool	_readPathRootless();
  bool	_readPathEmpty();

  bool	_readSegment();
  bool	_readSegmentNz();
  bool	_readSegmentNzNc();

  bool	_readPchar();
  bool	_readQuery();
  bool	_readFragment();
  bool	_readPctEncoded();

  bool	_readUnreserved();
  bool	_readReserved();

  bool	_readGenDelims();
  bool	_readSubDelims();
private:
  bool	_readAbsoluteURIOpt();

  bool	_readAuthorityOpt1();
  bool	_readAuthorityOpt2();

  bool	_readPathAbemptyPart2();

  bool	_readPathAbsoluteOpt();
  bool	_readPathAbsolutePart2();

  bool	_readPathNoSchemePart2();

  bool	_readPathRootlessPart2();
private:
  Consumer&	_consumer;
};

#endif // !__URIPARSER_H__
