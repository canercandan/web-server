//
// Server.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:53:56 2008 caner candan
// Last update Tue Sep 16 08:52:48 2008 caner candan
//

#include <iostream>
#include "Server.h"
#include "Socket.h"
#include "Client.h"
#include "Thread.h"
#include "Config.h"
#include "ServerState.h"
#include "Signal.h"

Server::Server(int port)
  : _port(port)
{
//   Signal*	signal = Signal::getInstance();

//   signal->addCallback(Signal::INT, this,
// 		      static_cast<ISignalManager::callback>
// 		      (&Server::signal));
}

void	Server::run()
{
  Logger	logger;

  logger.info("starting zia server");
  if (!this->_server.create(this->_port))
    {
      logger.error("an error occured while starting the server");
      return;
    }
  ServerState::getInstance()->setState(ServerState::PROCESS);
  this->_loop();
  this->_stop();
}

void	Server::_loop()
{
  Logger	logger;

  while (ServerState::getInstance()->getState()
	 == ServerState::PROCESS)
    {
      Socket*	socket;

      if ((socket = this->_server.accept()))
	{
	  Client*	client = new Client(socket);
	  Thread	thread(client);

	  logger.info("accept new connection from a client");
	  thread.start();
	}
    }
}

void	Server::_stop()
{
  Logger	logger;

  this->_server.close();
  ServerState::getInstance()->setState(ServerState::BREAK);
  Config::kill();
  ServerState::kill();
  logger.info("stopping zia server");
}

void	Server::signal()
{
  this->_stop();
}
