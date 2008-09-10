//
// main.cpp for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Wed Sep 10 17:20:29 2008 florent hochwelker
//

#include <iostream>
#include <sstream>
#include "Config.h"
#include "Logger.h"
#include "ServerSocket.h"
#include "Thread.h"

using namespace ZenZiAPI;

int		main()
{
  Config*	conf = Config::getInstance();
  Logger	logger;
  ServerSocket	server;

  //conf->ziaDumpConfig();
  logger.info("starting zia server");

  Socket*		socket;
  //   Client*		client;
  //  Thread*		thread;
  //   int			port;
  //   std::stringstream	ss(conf->getValue("port"));

  //   conf->ziaDumpConfig();
  //   ss >> port;

  if (!server.create(conf->getParamInt("port")))
    {
      logger.error("an error occured while starting the server");
      return (1);
    }
  while (42) //todo: singleton State to check error
    if ((socket = server.accept()))
      {
	logger.info("accept new connection from a client");
	//client = new Client(socket);
	// 	thread = new Thread(client);
	// 	thread->start();
	// 	delete thread;
      }
  server.close();
  //   conf->kill();
  logger.info("stopping zia server");
  return (0);
}
