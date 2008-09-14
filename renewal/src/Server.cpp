//
// Server.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:53:56 2008 caner candan
// Last update Sun Sep 14 19:04:26 2008 caner candan
//

#include <iostream>
#include "Server.h"
#include "Socket.h"
#include "Client.h"
#include "Thread.h"
#include "Config.h"
#include "ServerState.h"
#include "Signal.h"

Server::Server()
{
  Signal*	signal = Signal::getInstance();

  signal->addCallback(Signal::INT, this,
		      static_cast<ISignalManager::callback>
		      (&Server::signal));
}

void	Server::start()
{
  this->_logger.info("starting zia server");
  if (!this->_server.create(Config::getInstance()->getParamInt("port")))
    {
      this->_logger.error("an error occured while starting the server");
      return;
    }
  ServerState::getInstance()->setState(ServerState::PROCESS);
}

void	Server::loop()
{
  Socket*	socket;

  while (ServerState::getInstance()->getState()
	 == ServerState::PROCESS)
    {
      if ((socket = this->_server.accept()))
	{
	  Client*	client = new Client(socket);
	  Thread	thread(client);

	  this->_logger.info("accept new connection from a client");
	  thread.start();
	}
    }
}

void	Server::stop()
{
  this->_server.close();
  ServerState::getInstance()->setState(ServerState::BREAK);
  Config::kill();
  ServerState::kill();
  this->_logger.info("stopping zia server");
}

void	Server::signal()
{
  std::cout << "server stop" << std::endl;
  this->stop();
}
