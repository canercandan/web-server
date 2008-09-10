//
// Server.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:53:56 2008 caner candan
// Last update Wed Sep 10 18:10:20 2008 caner candan
//

#include "Server.h"
#include "Socket.h"

Server::Server(int port)
{
  _refreshListModule();
}

void	Server::_refreshListModule()
{}

void	Server::start()
{
  this->_logger.info("starting zia server");
  if (!this->_server.create(conf->getParamInt("port")))
    {
      this->_logger.error("an error occured while starting the server");
      return (1);
    }
}

void	Server::loop()
{
  Socket*	socket;

  while (42) //todo: singleton State to check error
    {
      if ((socket = this->_server.accept()))
	{
	  this->_logger.info("accept new connection from a client");
	}
    }
}

void	Server::stop()
{
  this->_server.close();
}
