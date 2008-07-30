//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Wed Jul 30 12:28:31 2008 morgan armand
//

#include "Logger.h"
#include "ServerSocket.h"

int		main(int ac, char **av)
{
  Logger	logger;
  ServerSocket	server;
  Socket*	client;

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
	  pthread_create();
	  logger.info("accept new connection from a client");
	}
    }
  server.close();
  logger.info("stopping zia server");
  return (0);
}
