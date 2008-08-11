//
// HttpResponse.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 14:56:59 2008 morgan armand
** Last update Mon Aug 11 12:54:34 2008 majdi toumi
//

#ifndef __HTTP_RESPONSE_H__
#define __HTTP_RESPONSE_H__

#include <string>
#include "HttpRequest.h"

class		HttpResponse
{
 public:
  HttpResponse(const HttpRequest& req);
  ~HttpResponse();

  void		setStatusLine();

 private:
  HttpRequest	_req;
  unsigned int	_status_code;
  std::string	_status_line;

  std::string	_response;
};

#endif // __HTTP_RESPONSE_H__
