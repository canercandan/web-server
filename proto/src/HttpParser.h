//
// HttpParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:27:44 2008 morgan armand
// Last update Sat Aug  2 14:07:43 2008 morgan armand
//

#ifndef __HTTP_PARSER_H__
#define __HTTP_PARSER_H__

#include "IRunnable.h"
#include "HttpConsumer.h"

class	HttpParser : public HttpConsumer, public IRunnable
{
public:
  HttpParser(HttpProducer* prod);

  // Thread entry point.
  void	run();

  // Read a HTTP request, and fill a HttpRequest object
  bool	readRequest(/*HttpRequest& req*/);

  bool	readRequestLine();
  bool	readMethod();
  bool	readExtensionMethod();
  bool	readRequestURI();
  bool	readAbsoluteURI();
  bool	readAbsPath();
  bool	readAuthority();
  bool	readHttpVersion();
};

#endif // __HTTP_PARSER_H__
