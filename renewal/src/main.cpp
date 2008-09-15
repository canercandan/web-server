//
// main.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Mon Sep 15 17:54:31 2008 caner candan
//

#include <sstream>
#include <iostream>
#include "Server.h"
#include "Config.h"
#include "Thread.h"
#include "Logger.h"

int		main()
{
  Config*	conf = Config::getInstance();

  XmlParser::listParam	list(conf->getListParam("//config"));

  for (XmlParser::listParam::const_iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      const XmlParser::listAttribute&	attr = *it;

      std::stringstream	ss(attr.at("port"));
      int		port;

      ss >> port;

      Server*	server = new Server(port);
      Thread	thread(server);
      Logger	logger;

      logger.info("accept new port");
      thread.start();
      std::cout << "debug: [" << attr.at("port") << ']' << std::endl;
    }
}
