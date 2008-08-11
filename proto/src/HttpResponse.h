//
// HttpResponse.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:59 2008 morgan armand
** Last update Mon Aug 11 15:46:26 2008 majdi toumi
//

#ifndef __HTTP_RESPONSE_H__
#define __HTTP_RESPONSE_H__

#include <iostream>
#include <string>
#include "Socket.h"
#include "HttpRequest.h"

class			HttpResponse
{
 public:
  HttpResponse(const HttpRequest& req);
  ~HttpResponse();
  void			sendResponse(Socket* sck);

 private:
  HttpRequest&		_req;

  std::string		generateHeader();
  std::string		generateStatusLine();
  std::iostream&	generateMessageBody();
};

#endif // __HTTP_RESPONSE_H__
