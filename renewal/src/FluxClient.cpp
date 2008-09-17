//
// FluxClient.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:39 2008 caner candan
// Last update Wed Sep 17 02:45:21 2008 morgan armand
//

#ifdef WIN32
# include <time.h>
#else
# include <ctime>
# include <sys/types.h>
# include <sys/socket.h>
#endif

#include <sstream>
#include "FluxClient.h"
//#include "ITools.h"
#include "Config.h"
//#include "Socket.h"

FluxClient::FluxClient(HookManager& hook, ZenZiAPI::ITools& tools)
  : _hook(hook), _tools(tools)
{}

FluxClient::~FluxClient()
{
}

std::string		FluxClient::nextString()
{
  char			buf[128];
  int			cc;
  Config*		conf;
  int			timeout;
  int			timestart;

  std::cout << "ENTER: read" << std::endl;
  conf = Config::getInstance();
  timeout = conf->getParamInt("timeout");
  timestart = conf->getParamInt("timestart");
  //if (timeout > 0 && timestart + timeout >= ::time(NULL))
  //    return ("");
  if (this->_hook.manageHookPoint(ZenZiAPI::READ, this->_tools))
    {
      std::cout << "manageHookPoint returns true" << std::endl;
      return (*this->_tools.data());
    }
  if ((cc = ::recv(this->_tools.connectInfos().getSocket(), buf, sizeof(buf) - 1, 0)) == 0)
    {
      std::cout << "bllll" << std::endl;
      return ("");
    }

  buf[cc] = 0;
  std::cout << "LEAVE: read with [" << buf << "]" << std::endl;
  return (buf);
}
