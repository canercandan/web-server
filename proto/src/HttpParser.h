//
// HttpParser.h for HttpParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:17:04 2008 caner candan
// Last update Wed Aug  6 13:46:07 2008 caner candan
//

#include "URIParser.h"

class	HttpParser : public URIParser
{
public:
  HttpParser();
  ~HttpParser();

  void	run();
  bool	readRequest();
//   bool	readRequestLine();
//   bool	readMethod();
//   bool	readRequestURI();
//   bool	readExtensionMethod();
//   bool	readHttpVersion();
//   bool	readGeneralHeader();
//   bool	readCacheControl();
//   bool	readConnection();
//   bool	readDate();
//   bool	readPragma();
//   bool	readTrailer();
//   bool	readTransferEncoding();
//   bool	readUpgrade();
//   bool	readVia();
//   bool	readWarning();
};
