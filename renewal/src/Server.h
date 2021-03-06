//
// Server.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:25:17 2008 caner candan
// Last update Tue Sep 16 17:30:00 2008 caner candan
//

#ifndef __SERVER_H__
# define __SERVER_H__

# include <list>
# include <string>
# include "Logger.h"
# include "ServerSocket.h"
# include "IRunnable.h"
# include "ISignalManager.h"

class	Server : public ISignalManager, public IRunnable
{
public:
  Server(int port, const std::string& type);

  void	run();

  void	signal();
private:
  void	_loop();
  void	_stop();
private:
  int		_port;
  std::string	_type;
  ServerSocket	_server;
};

#endif //! __SERVER_H__
