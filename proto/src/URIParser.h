//
// URIParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 14:34:33 2008 morgan armand
// Last update Sat Aug  2 14:40:53 2008 morgan armand
//

#ifndef __URI_PARSER_H__
#define __URI_PARSER_H__

#include "HttpConsumer.h"

class	URIParser : public HttpConsumer
{
public:
  URIParser(HttpProducer* prod);

  bool	readRequestURI();
  bool	readAbsoluteURI();
  bool	readAbsPath();
  bool	readAuthority();
  bool	readPathSegments();
};

#endif // __URI_PARSER_H__
