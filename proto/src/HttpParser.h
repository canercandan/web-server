//
// HttpParser.h for HttpParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:17:04 2008 caner candan
// Last update Fri Aug  8 11:09:00 2008 caner candan
//

#ifndef __HTTPPARSER_H__
# define __HTTPPARSER_H__

# include "URIParser.h"
# include "HttpRequest.h"

class	HttpParser : public URIParser
{
public:
  HttpParser(HttpProducer* prod, HttpRequest* req);
  ~HttpParser();

  void	run();
  bool	readRequest();
  bool	readRequestLine();
  bool	readMethod();
  bool	readRequestURI();
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
private:
  HttpRequest*	_req;
};

#endif // !__HTTPPARSER_H__
