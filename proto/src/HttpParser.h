//
// HttpParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:27:44 2008 morgan armand
// Last update Wed Jul 30 17:31:44 2008 morgan armand
//

#ifndef __HTTP_PARSER_H__
#define __HTTP_PARSER_H__

#include "HttpProducer.h"

class	HttpParser
{
public:
  HttpParser(HttpProducer* prod);

  // Main rule. Read an entire HTTP Request.
  bool	readHttpRequest(/*HttpRequest& req*/);

private:
  HttpProducer*	_prod;
  std::string	_buff;
};

#endif // __HTTP_PARSER_H__
