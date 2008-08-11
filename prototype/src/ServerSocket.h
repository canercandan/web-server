//
// ServerSocket.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 10:33:28 2008 morgan armand
// Last update Wed Jul 30 12:25:46 2008 morgan armand
//

#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__

#include "Socket.h"

class	ServerSocket
{
public:
  ServerSocket();

  // Create a server socket, listening to the given port.
  bool		create(int port);

  // Wrapper to accept() method of Socket class
  Socket*	accept();

  // Wrapper to close() method of Socket class
  void		close();

private:
  Socket	_sck;
};

#endif // __SERVER_SOCKET_H__
