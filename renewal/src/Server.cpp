//
// Server.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:53:56 2008 caner candan
// Last update Tue Sep 23 15:13:29 2008 caner candan
//

#include <iostream>
#include "Server.h"
#include "Socket.h"
#include "Client.h"
#include "Thread.h"
#include "Config.h"
#include "ServerState.h"
#include "Signal.h"

Server::Server(int port, const std::string& type)
  : _port(port), _type(type)
{
  Signal*	signal = Signal::getInstance();

  signal->addCallback(Signal::INT, this,
		      static_cast<ISignalManager::callback>
		      (&Server::signal));
}

void	Server::run()
{
  Logger::Info	info(this->_type);

  info << "starting zia server | "
       << "port: " << this->_port << "\r\n";
  if (!this->_server.create(this->_port))
    {
      Logger::Error	error("server create");

      error << "an error occured while starting the server\n";
      return;
    }
  ServerState::getInstance()->setState(ServerState::PROCESS);
  this->_loop();
  this->_stop();
}

void	Server::_loop()
{
  Logger::Info	info(this->_type);

  info << "wait client\n";
  while (ServerState::getInstance()->getState()
	 == ServerState::PROCESS)
    {
      Socket*	socket;

      if ((socket = this->_server.accept()))
	{
	  Client*	client = new Client(socket, this->_type);
	  Thread	thread(client);
	  Logger::Info	info;

	  info << "accept new connection from a client\n";
	  thread.start();
	}
    }
}

void	Server::_stop()
{
  Logger::Info	info(this->_type);

  this->_server.close();
  ServerState::getInstance()->setState(ServerState::BREAK);
  ServerState::kill();
  info << "stopping zia server";
  std::cout << std::endl;
}

void	Server::signal()
{
  this->_stop();
}
