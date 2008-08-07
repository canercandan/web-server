//
// URIParser.h for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:19:54 2008 caner candan
// Last update Thu Aug  7 11:27:52 2008 morgan armand
//

#ifndef __URI_PARSER_H__
#define __URI_PARSER_H__

#include "ABNFParser.h"

class	URIParser : public ABNFParser
{
public:
  URIParser(HttpProducer* prod);
  ~URIParser();

  bool	readURI();
  bool	readHierPart();
  bool	readURIReference();
  bool	readAbsoluteURI();
  bool	readRelativeRef();
  bool	readRelativePart();

  bool	readScheme();
  bool	readSchemeLoop();

  bool	readAuthority();

  bool	readUserinfo();

  bool	readHost();

  bool	readPort();

  bool	readIPLiteral();

  bool	readIPvFuture();
  bool	readIPvFutureLoop1();
  bool	readIPvFutureLoop2();

  bool	readIPv6address();
  bool	readH16();
  bool	readLs32();
  bool	readIPv4address();
  bool	readDecOctet();

  bool	readRegName();

  bool	readPath();

  bool	readPathAbempty();

  bool	readPathAbsolute();
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
};

#endif // __URI_PARSER_H__
