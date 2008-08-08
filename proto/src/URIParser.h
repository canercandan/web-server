//
// URIParser.h for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:19:54 2008 caner candan
// Last update Fri Aug  8 11:09:08 2008 caner candan
//

#ifndef __URIPARSER_H__
#define __URIPARSER_H__

#include "ABNFParser.h"
#include "HttpRequest.h"

class	URIParser : public ABNFParser
{
public:
  URIParser(HttpProducer* prod,
	    HttpRequest* req);
  ~URIParser();

  bool	readURI();
  bool	readURIBool1();
  bool	readURIBool2();

  bool	readHierPart();
  bool	readHierPartBlock();

  bool	readURIReference();

  bool	readAbsoluteURI();
  bool	readAbsoluteURIBool();

  bool	readRelativeRef();
  bool	readRelativeRefBool1();
  bool	readRelativeRefBool2();

  bool	readRelativePart();
  bool	readRelativePartBlock();

  bool	readScheme();
  bool	readSchemeLoop();

  bool	readAuthority();
  bool	readAuthorityBool1();
  bool	readAuthorityBool2();

  bool	readUserinfo();
  bool	readHost();
  bool	readPort();

  bool	readIPLiteral();
  bool	readIPLiteralBlock();

  bool	readIPvFuture();
  bool	readIPvFutureLoop1();
  bool	readIPvFutureLoop2();

  bool	readIPv6address();
  bool	readH16();

  bool	readLs32();
  bool	readLs32Block();

  bool	readIPv4address();

  bool	readDecOctet();
  bool	readDecOctetBlock1();
  bool	readDecOctetBlock2();
  bool	readDecOctetBlock3();
  bool	readDecOctetBlock4();

  bool	readRegName();
  bool	readPath();
  bool	readPathAbempty();

  bool	readPathAbsolute();
  bool	readPathAbsoluteBool();
  bool	readPathAbsoluteLoop();

  bool	readPathNoscheme();
  bool	readPathNoschemeLoop();

  bool	readPathRootless();
  bool	readPathRootlessLoop();

  bool	readPathEmpty();

  bool	readSegment();
  bool	readSegmentNz();

  bool	readSegmentNzNc();
  bool	readSegmentNzNcLoop();

  bool	readPchar();
  bool	readQuery();
  bool	readFragment();
  bool	readPctEncoded();
  bool	readUnreserved();
  bool	readReserved();
  bool	readGenDelims();
  bool	readSubDelims();
private:
  HttpRequest*	_req;
};

#endif // __URIPARSER_H__
