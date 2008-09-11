//
// FluxClient.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:39 2008 caner candan
// Last update Thu Sep 11 15:04:25 2008 morgan armand
//

#ifdef WIN32
# include <time.h>
#else
# include <ctime>
#endif

#include <sstream>
#include "FluxClient.h"
#include "Config.h"
#include "Socket.h"

FluxClient::FluxClient(Socket* sck)
  : _sck(sck)
{}

FluxClient::~FluxClient()
{
  if (_sck)
    _sck->close();
}

std::string		FluxClient::nextString()
{
  char			buf[128];
  int			cc;
  Config*		conf;
  int			timeout;
  int			timestart;

  conf = Config::getInstance();
  timeout = conf->getParamInt("timeout");
  timestart = conf->getParamInt("timestart");
  //if (timeout > 0 && timestart + timeout >= ::time(NULL))
  //    return ("");
  if (!(cc = this->_sck->recv(buf, sizeof(buf) - 1)))
    return ("");
  buf[cc] = 0;
  return (buf);
}
