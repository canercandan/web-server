//
// Message.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:50:10 2008 caner candan
// Last update Sun Sep 14 11:32:01 2008 caner candan
//

#ifndef _MESSAGE_H_
# define _MESSAGE_H_

# include "IMessage.hpp"
# include "Request.h"
# include "Response.h"

class	Message : public ZenZiAPI::IMessage
{
public:
  ZenZiAPI::IRequest&		request();
  ZenZiAPI::IResponse&		response();
private:
  Response	_response;
};

#endif // !_MESSAGE_H_
