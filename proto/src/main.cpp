//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Sun Aug  3 13:44:16 2008 caner candan
//

#include <iostream>
#include "Logger.h"
#include "Thread.h"
#include "HttpProducer.h"
#include "HttpConsumer.h"
#include "ServerSocket.h"

int		main(void)
{
  Logger	logger;
  ServerSocket	server;
  Socket*	client;
  Thread*	thread;
  HttpProducer*	prod;
  HttpConsumer*	consum;
  HttpRequest*	req;

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
	  req = new HttpRequest;
	  consum = new HttpConsumer(prod, req);
	  thread = new Thread(consum);
	  thread->start();
	}
    }
  server.close();
  logger.info("stopping zia server");
  return (0);
}
