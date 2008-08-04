//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Mon Aug  4 10:03:16 2008 User Toumi_m
//

#include <iostream>
#include <sstream>
#include "Logger.h"
#include "Thread.h"
#include "HttpProducer.h"
#include "HttpConsumer.h"
#include "ServerSocket.h"
#include "XmlDomConfig.h"

int			main(void)
{
  Logger		logger;
  ServerSocket		server;
  Socket*		client;
  Thread*		thread;
  HttpProducer*		prod;
  HttpConsumer*		consum;
  HttpRequest*		req;
  XmlDomConfig*		xml;
  int			port;

  xml = new XmlDomConfig(SERVER_CONF);
  xml->xmlDumpConfig();
  std::istringstream value(xml->getValue("port"));
  value >> port;
  logger.info("starting zia server");
  if (!server.create(port))
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
