//
// URIParser.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Fri Sep 12 15:33:26 2008 caner candan
// Last update Fri Sep 12 15:33:27 2008 caner candan
//

#ifndef __URIPARSER_H__
# define __URIPARSER_H__

# include <string>
# include "IParser.h"
# include "Consumer.h"
# include "HttpParser.h"
# include "IRequest.hpp"

class	URIParser : public IParser
{
public:
  URIParser(Consumer& consumer, ZenZiAPI::IRequest& request);

  bool	run();
  bool	readHierPart();
  bool	readAbsoluteURI();
  bool	readScheme();
  bool	readAuthority();
  bool	readUserInfo();

  bool	readHost();
  bool	readPort();

  bool	readIPLiteral();
  bool	readIPvFuture();
  bool	readIPv6address();
  bool	readIPv4address();

  bool	readDecOctet();
  bool	readRegName();

  bool	readPath();
  bool	readPathAbempty();
  bool	readPathAbsolute();
  bool	readPathAbsoluteQuery();
  bool	readPathNoScheme();
  bool	readPathRootless();
  bool	readPathEmpty();

  bool	readSegment();
  bool	readSegmentNz();
  bool	readSegmentNzNc();

  bool	readPchar();
  bool	readQuery();
  bool	readFragment();
  bool	readPctEncoded();

  bool	readUnreserved();
  bool	readReserved();

  bool	readGenDelims();
  bool	readSubDelims();
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
  Consumer&		_consumer;
  ZenZiAPI::IRequest&	_request;
};

#endif // !__URIPARSER_H__
