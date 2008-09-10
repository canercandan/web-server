//
// Server.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:25:17 2008 caner candan
// Last update Wed Sep 10 18:07:21 2008 caner candan
//

#ifndef __SERVER_H__
# define __SERVER_H__

# include <list>
# include <string>
# include "Logger.h"
# include "ServerSocket.h"

class	Server
{
public:
  typedef std::list<std::string>	listModule;
public:
  Server(int port);

  void	start();
  void	loop();
  void	stop();
private:
  void	_refreshListModule();
private:
  Logger	_logger;
  ServerSocket	_server;
  listModule	_listModule;
};

#endif //! __SERVER_H__
