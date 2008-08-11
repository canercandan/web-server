//
// HttpResponse.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:33:37 2008 morgan armand
// Last update Mon Aug 11 15:01:53 2008 majdi toumi
//

#include <iostream>
#include <string>
#include "HttpResponse.h"

HttpResponse::HttpResponse(const HttpRequest& req, Socket* sck)
  : _req(req), _sck(sck)
{
  _status_code = -1;
  _status_line = "";
}

HttpResponse::~HttpResponse()
{
}

HttpResponse::setStatusCode()
{

}

HttpResponse::setStatusLine()
{
  this->_statusLine = ;
}
