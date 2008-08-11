//
// HttpResponse.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:33:37 2008 morgan armand
// Last update Mon Aug 11 20:19:45 2008 majdi toumi
//

#include <iostream>
#include <string>
#include "HttpResponse.h"

HttpResponse::HttpResponse(const HttpRequest* req)
  : _req(req)
{
}

HttpResponse::~HttpResponse()
{
}

void		HttpResponse::sendResponse(Socket*)
{
  std::string	status_line;

  std::cout << "debuG response:" << std::endl;
  this->generateMapError();
  status_line = generateStatusLine();
  std::cout << "Status line = " << status_line << std::endl;
}

void		HttpResponse::generateMapError()
{
  this->_map_error[100] = "Continue";
  this->_map_error[101] = "Switching Protocols";

  this->_map_error[200] = "OK";
  this->_map_error[201] = "Created";
  this->_map_error[202] = "Accepted";
  this->_map_error[203] = "Non-Authoritative Information";
  this->_map_error[204] = "No Content";
  this->_map_error[205] = "Reset Content";
  this->_map_error[206] = "Partial Content";

  this->_map_error[300] = "Multiple Choices";
  this->_map_error[301] = "Moved Permanently";
  this->_map_error[302] = "Found";
  this->_map_error[303] = "See Other";
  this->_map_error[304] = "Not Modified";
  this->_map_error[305] = "Use Proxy";
  this->_map_error[307] = "Temporary Redirect";

  this->_map_error[400] = "Bad Request";
  this->_map_error[401] = "Unauthorized";
  this->_map_error[402] = "Payment Required";
  this->_map_error[403] = "Forbidden";
  this->_map_error[404] = "Not Found";
  this->_map_error[405] = "Method Not Allowed";
  this->_map_error[406] = "Not Acceptable";
  this->_map_error[407] = "Proxy Authentication Required";
  this->_map_error[408] = "Request Time-out";
  this->_map_error[409] = "Conflict";
  this->_map_error[410] = "Gone";

  this->_map_error[411] = "Length Required";
  this->_map_error[412] = "Precondition Failed";
  this->_map_error[413] = "Request Entity Too Large";
  this->_map_error[414] = "Request-URI Too Large";
  this->_map_error[414] = "Unsupported Media Type";
  this->_map_error[416] = "Requested range not satisfiable";
  this->_map_error[417] = "Expectation Failed";

  this->_map_error[500] = "Internal Server Error";
  this->_map_error[501] = "Not Implemented";
  this->_map_error[502] = "Bad Gateway";
  this->_map_error[503] = "Service Unavailable";
  this->_map_error[504] = "Gateway Time-out";
  this->_map_error[505] = "HTTP Version not supported";
}

std::string	HttpResponse::generateHeader()
{
  return ("");
}

std::string	HttpResponse::generateStatusLine()
{
  std::string	http_version;
  //  unsigned int	status_code;
  //   std::string	reason_phrase;

  //  status_code = defineStatusCode();
  http_version = "HTTP/"; // + "x.x";
  //     + this->generateStatusCode()
  //     + this->generateReasonPhrase()
  return (http_version + "/r/n");
}

std::string	HttpResponse::defineStatusCode()
{
  return ("");
}

// std::iostream&	HttpResponse::generateMessageBody()
// {
// }

