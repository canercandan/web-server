//
// main.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Sat Sep 20 21:41:12 2008 caner candan
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
}
