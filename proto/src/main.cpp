//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Mon Aug  4 18:44:40 2008 User Toumi_m
//

#include <iostream>
#include <sstream>
#include "Client.h"
#include "Logger.h"
#include "Thread.h"
#include "ServerSocket.h"
#include "ParserXml.h"

int			main(void)
{
  Logger		logger;
  ServerSocket		server;
  Socket*		socket;
  Client*		client;
  Thread*		thread;
  ParserXml*		xml;
  ZiaConfiguration	conf;

  xml = new ParserXml(SERVER_XML);
  xml->xmlDumpConfig();
  conf = xml->xmlLoadConfig();
  logger.info("starting zia server");
  if (!server.create(conf.getPort()))
    {
      logger.error("an error occured while starting the server");
      return (1);
    }
  while (42)
    {
      if (socket = server.accept())
	{
	  logger.info("accept new connection from a client");
	  client = new Client(socket);
	  thread = new Thread(client);
	  thread->start();
	  delete thread;
	}
    }
  server.close();
  logger.info("stopping zia server");
  return (0);
}
