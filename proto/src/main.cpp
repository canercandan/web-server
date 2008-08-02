//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Sat Aug  2 17:50:05 2008 caner candan
//

#include <iostream>
#include "Logger.h"
#include "Thread.h"
#include "HttpParser.h"
#include "HttpProducer.h"
#include "ServerSocket.h"

int		main(void)
{
  Logger	logger;
  ServerSocket	server;
  Socket*	client;
  Thread*	thread;
  HttpParser*	parser;
  HttpProducer*	prod;

  logger.info("starting zia server");
  if (!server.create(4242))
    {
      logger.error("an error occured while starting the server");
      return (1);
    }
  while (42)
    {
      if (client = server.accept())
	{
	  logger.info("accept new connection from a client");
	  prod = new HttpProducer(client);
	  parser = new HttpParser(prod);
	  thread = new Thread(parser);
	  thread->start();
	}
    }
  server.close();
  logger.info("stopping zia server");
  return (0);
}
