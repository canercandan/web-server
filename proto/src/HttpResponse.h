//
// HttpResponse.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:59 2008 morgan armand
// Last update Mon Aug 11 21:07:07 2008 florent hochwelker
//

#ifndef __HTTP_RESPONSE_H__
#define __HTTP_RESPONSE_H__

#include <ifstream>
#include <string>
#include <map>
#include "Socket.h"
#include "HttpRequest.h"

class					HttpResponse
{
public:
  HttpResponse(const HttpRequest* req);
  ~HttpResponse();
  void					sendResponse(Socket* sck);

private:
  const HttpRequest*			_req;
  std::map<std::string, std::string>	_map_response;

  std::string		generateHeader();
  std::string		generateStatusLine();
  std::ifstream*	generateMessageBody();
  void			generateMapResponse();
  std::string		generateStatusLine();
  std::string		defineStatusCode();
  std::string		generateReasonPhrase();
};

#endif // __HTTP_RESPONSE_H__
