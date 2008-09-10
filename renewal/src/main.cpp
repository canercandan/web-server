//
// main.cpp for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Wed Sep 10 12:05:13 2008 majdi toumi
//

#include <iostream>
#include <sstream>
#include "Config.h"

using namespace ZenZiAPI;

int		main()
{
  Config*	conf = Config::getInstance();

  conf->ziaDumpConfig();

  //   Logger		logger;
//   ServerSocket		server;
//   ISocket*		socket;
//   Client*		client;
//   Thread*		thread;
//   int			port;
//   std::stringstream	ss(conf->getValue("port"));

//   conf->ziaDumpConfig();
//   ss >> port;
//   logger.info("starting zia server");
//   if (!server.create(port))
//     {
//       logger.error("an error occured while starting the server");
//       return (1);
//     }
//   while (42) //todo: singleton State to check error
//     if (socket = server.accept())
//       {
// 	logger.info("accept new connection from a client");
// 	client = new Client(socket);
// 	thread = new Thread(client);
// 	thread->start();
// 	delete thread;
//       }
//   server.close();
//   conf->kill();
//   logger.info("stopping zia server");
  return (0);
}
