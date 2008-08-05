//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Tue Aug  5 10:20:10 2008 morgan armand
//

#include <iostream>
#include <sstream>
#include "Client.h"
#include "Logger.h"
#include "Thread.h"
#include "ServerSocket.h"
#include "XmlDomConfig.h"

int			main(void)
{
  Logger		logger;
  ServerSocket		server;
  Socket*		socket;
  Client*		client;
  Thread*		thread;
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
