//
// ServerSocket.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 18:10:10 2008 caner candan
// Last update Wed Sep 10 18:10:10 2008 caner candan
//

#ifndef __SERVERSOCKET_H__
# define __SERVERSOCKET_H__

# include "Socket.h"

class	ServerSocket
{
public:
  bool		create(const int& port);
  Socket*	accept();
  void		close();
private:
  Socket	_sck;
};

#endif // !__SERVERSOCKET_H__
