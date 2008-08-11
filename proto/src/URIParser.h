//
// URIParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:05 2008 morgan armand
// Last update Mon Aug 11 11:51:42 2008 morgan armand
//

#ifndef __URI_PARSER_H__
#define __URI_PARSER_H__

#include "ABNFParser.h"
#include "HttpRequest.h"

class	URIParser : public ABNFParser
{
public:
  URIParser(HttpProducer* prod, HttpRequest* request);
  ~URIParser();

  bool	readHierPart();

  bool	readAbsoluteURI();
  bool	readAbsoluteURIOpt();

  bool	readScheme();

  bool	readAuthority();
  bool	readAuthorityOpt1();		// NOT RFC [userinfo "@"]
  bool	readAuthorityOpt2();		// NOT RFC [ ":" port ]

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
  bool	readPathAbemptyPart2();		// NOT RFC ("/" segment)

  bool	readPathAbsolute();
  bool	readPathAbsoluteOpt();		// NOT RFC
  bool	readPathAbsolutePart2();	// NOT RFC ("/" segment)

  bool	readPathNoScheme();
  bool	readPathNoSchemePart2();	// NOT RFC ("/" segment)

  bool	readPathRootless();
  bool	readPathRootlessPart2();	// NOT RFC ("/" segment)

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

protected:
  HttpRequest*	_request;
};

#endif // !__URI_PARSER_H__
