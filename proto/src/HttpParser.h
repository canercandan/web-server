//
// HttpParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:27:44 2008 morgan armand
// Last update Sat Aug  2 17:39:10 2008 morgan armand
//

#ifndef __HTTP_PARSER_H__
#define __HTTP_PARSER_H__

#include "IRunnable.h"
#include "URIParser.h"

class	HttpParser : public URIParser, public IRunnable
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
  bool	readHttpVersion();

  bool	readGeneralHeader();
  bool	readCacheControl();
  bool	readConnection();
  bool	readDate();
  bool	readPragma();
  bool	readTrailer();
  bool	readTransferEncoding();
  bool	readUpgrade();
  bool	readVia();
  bool	readWarning();
};

#endif // __HTTP_PARSER_H__
