//
// FluxClient.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:39 2008 caner candan
// Last update Tue Sep  9 17:50:44 2008 caner candan
//

#ifdef WIN32
# include <time.h>
#else
# include <ctime>
#endif

#include <sstream>
#include "FluxClient.h"
#include "Config.h"

FluxClient::FluxClient(ISocket* sck)
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
  std::stringstream	ss;
  int			timeout;
  int			timestart;

  conf = Config::getInstance();
  ss.str(conf->getValue("timeout"));
  ss >> timeout;
  ss.str(conf->getValue("timestart"));
  ss >> timestart;
  if (timeout > 0 && timestart + timeout >= ::time(NULL))
    return ("");
  if (!(cc = this->_sck->recv(buf, sizeof(buf) - 1)))
    return ("");
  buf[cc] = 0;
  return (buf);
}
