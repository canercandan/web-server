//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Wed Jul 30 20:00:53 2008 morgan armand
//


#include <iostream>
#include "Logger.h"
#include "HttpParser.h"
#include "HttpProducer.h"
#include "ServerSocket.h"

#ifdef WIN32
# include <windows.h>
#else
# include <pthread.h>
#endif

#ifdef WIN32
DWORD WINAPI	run(LPVOID arg)
#else
  void*		run(void* arg)
#endif
{
  Socket*	sck;
  HttpProducer*	prod;
  HttpParser*	parser;

  sck = (Socket *)arg;
  prod = new HttpProducer(sck);
  parser = new HttpParser(*prod);

  if (parser->readHttpRequest())
    {
    }

  delete prod;
  delete parser;

  return (NULL);
}

int		main(int ac, char **av)
{
  Logger	logger;
  ServerSocket	server;
  Socket*	client;
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
	  parser = new HttpParser(*prod);
	}
    }
  server.close();
  logger.info("stopping zia server");
  return (0);
}
