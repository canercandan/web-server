//
// HttpProducer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:13:12 2008 morgan armand
// Last update Sun Aug 31 15:54:04 2008 caner candan
//

#ifdef WIN32
#include <time.h>
#else
#include <ctime>
#endif
#include <sstream>
#include "HttpProducer.h"
#include "ZiaConfiguration.h"

HttpProducer::HttpProducer(Socket* sck)
  : _sck(sck)
{
}

HttpProducer::~HttpProducer()
{
  if (_sck)
    {
      _sck->close();
      
    }
}

std::string		HttpProducer::nextString(void)
{
  char			buf[128];
  int			cc;
  ZiaConfiguration*	conf;
  std::stringstream	ss;
  int			timeout;
  int			timestart;

  conf = ZiaConfiguration::getInstance();
  ss.str(conf->getParserXml()->xmlGetValue("/server/config/timeout[@value]"));
  ss >> timeout;
  ss.str(conf->getValue("timestart"));
  ss >> timestart;
  if (timeout > 0 && timestart + timeout >= ::time(NULL))
    return (std::string(""));
  if (!(cc = this->_sck->recv(buf, sizeof(buf) - 1)))
    return (std::string(""));
  buf[cc] = 0;
  return (std::string(buf));
}
