#include <iostream>
#include <sstream>
#include "Logger.h"
#include "Client.h"
#include "Thread.h"
#include "ServerSocket.h"
#include "Socket.h"
#include "Config.h"

using namespace ziApi;

int			main(void)
{
  Config*		conf = Config::getInstance();
  Logger		logger;
  ServerSocket		server;
  ISocket*		socket;
  Client*		client;
  Thread*		thread;
  int			port;
  std::stringstream	ss(conf->getValue("port"));

  conf->ziaDumpConfig();
  ss >> port;
  logger.info("starting zia server");
  if (!server.create(port))
    {
      logger.error("an error occured while starting the server");
      return (1);
    }
  while (42) //todo: singleton State to check error
    if (socket = server.accept())
      {
	logger.info("accept new connection from a client");
	client = new Client(socket);
	thread = new Thread(client);
	thread->start();
	delete thread;
      }
  server.close();
  conf->kill();
  logger.info("stopping zia server");
  return (0);
}
