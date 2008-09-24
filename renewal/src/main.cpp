//
// main.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Tue Sep 23 15:13:30 2008 caner candan
//

#include <sstream>
#include <iostream>
#include "Server.h"
#include "Config.h"
#include "Thread.h"
#include "Logger.h"

int		main()
{
  Config*		conf = Config::getInstance();
  std::list<Thread*>	threads;
  XmlParser::listParam	list(conf->getListParam("//config"));

#ifdef WIN32
  int		err;
  WSADATA	wsaData;

  if ((err = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
      std::cerr << "WSAStartup failed with error " << err << std::endl;
      return (false);
    }

  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
      std::cerr << "Could not find a useable version of winsock.dll" << std::endl;
      WSACleanup();
      return (false);
    }
#endif

  for (XmlParser::listParam::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      XmlParser::listAttribute&	attr = *it;

      std::stringstream	ss(attr["port"]);
      int		port;

      ss >> port;

      Server*	server = new Server(port, attr["type"]);
      Thread*	thread = new Thread(server);

      thread->start();
      threads.push_back(thread);
    }
  for (std::list<Thread*>::iterator
	 it = threads.begin(),
	 end = threads.end();
       it != end; ++it)
    (*it)->join();
  for (std::list<Thread*>::iterator
	 it = threads.begin(),
	 end = threads.end();
       it != end; ++it)
    delete (*it);
  Config::kill();
#ifdef WIN32
      WSACleanup();
#endif
}
