//
// Message.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:50:29 2008 caner candan
// Last update Sun Sep 14 09:54:25 2008 caner candan
//

#include "Message.h"

ZenZiAPI::IRequest&	Message::request()
{
  return (this->_response);
}

ZenZiAPI::IResponse&	Message::response()
{
  return (this->_response);
}
