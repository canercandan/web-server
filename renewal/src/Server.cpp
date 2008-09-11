//
// Server.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:53:56 2008 caner candan
// Last update Thu Sep 11 11:56:52 2008 caner candan
//

#include "Server.h"
#include "Socket.h"
#include "Client.h"
#include "Thread.h"
#include "Config.h"
#include "ServerState.h"

void	Server::start()
{
  this->_logger.info("starting zia server");
  if (!this->_server.create(Config::getInstance()->getParamInt("port")))
    this->_logger.error("an error occured while starting the server");
  else
    ServerState::getInstance()->setState(ServerState::PROCESS);
}

void	Server::loop()
{
  Socket*	socket;
  Client*	client;
  Thread*	thread;

  while (ServerState::getInstance()->getState()
	 == ServerState::PROCESS)
    {
      if ((socket = this->_server.accept()))
	{
	  this->_logger.info("accept new connection from a client");
	  client = new Client(socket);
	  thread = new Thread(client);
	  thread->start();
	  delete thread;
	}
    }
}

void	Server::stop()
{
  this->_server.close();
  ServerState::getInstance()->setState(ServerState::BREAK);
  this->_logger.info("stopping zia server");
}
