//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:24 2008 morgan armand
// Last update Tue Aug 12 16:55:48 2008 caner candan
//

#include <sstream>
#include "HttpRequest.h"

HttpRequest::HttpRequest()
{
  _httpUrl.getHost().setPort(80);
}
