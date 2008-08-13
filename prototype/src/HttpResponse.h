//
// HttpResponse.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:59 2008 morgan armand
// Last update Wed Aug 13 18:53:04 2008 majdi toumi
//

#ifndef __HTTP_RESPONSE_H__
#define __HTTP_RESPONSE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Socket.h"
#include "HttpRequest.h"
#include "ZiaConfiguration.h"

class				HttpResponse
{
public:
  HttpResponse(HttpRequest* req);
  ~HttpResponse();
  void				sendResponse(Socket* sck);

private:
  HttpRequest*			_req;
  ZiaConfiguration*		_conf;
  int				_status_code;
  std::map<int, std::string>	_map_response;

  void				generateMapResponse();
  std::string			generateResponse();
  std::string			createStatusLine();
  std::string			createGeneralHeader();
  std::string			createResponseHeader();
  std::string			createEntityHeader();
  int				findStatusCode();
  int				informationalCode();
  int				successfulCode();
  int				redirectionCode();
  int				clientErrorCode();
  int				serverErrorCode();
  void				sendMessageBody(Socket* sck);
};

#endif // __HTTP_RESPONSE_H__
