//
// HttpProducer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:13:12 2008 morgan armand
// Last update Sat Aug  2 11:40:28 2008 caner candan
//

#include "HttpProducer.h"

HttpProducer::HttpProducer(Socket* sck)
  : _sck(sck)
{
}

HttpProducer::~HttpProducer()
{
  if (_sck)
    _sck->close();
}

// std::string	HttpProducer::nextString(void)
// {
//   char		buf[16];
//   int		cc;

//   if ((cc = this->_sck->recv(buf, 15)) == 0)
//     return (NULL);

//   buf[cc] = 0;

//   return (new std::string(buf));
// }

std::string	HttpProducer::nextString(void)
{
  char		buf[128];
  int		cc;

  buf[0] = 0;
  if (!(cc = this->_sck->recv(buf, sizeof(buf))))
    return (std::string(""));
  buf[cc] = 0;
  return (std::string(buf));
}
