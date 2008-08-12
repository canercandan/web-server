//
// HttpResponse.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:59 2008 morgan armand
// Last update Tue Aug 12 01:38:34 2008 florent hochwelker
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

class	HttpResponse
{
public:
  HttpResponse(HttpRequest* req, const ZiaConfiguration& conf);
  ~HttpResponse();
  void			sendResponse(Socket* sck);

private:
  HttpRequest*			_req;
  const ZiaConfiguration&	_conf;
  std::map<std::string, std::string>	_map_response;

  std::string		generateHeader();
  std::string		generateStatusLine();
  void			sendMessageBody(Socket* sck);
  void			generateMapResponse();
  std::string		defineStatusCode();
  std::string		generateReasonPhrase();
  std::string		findStatusCode();
};

#endif // __HTTP_RESPONSE_H__
