//
// Client.h for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:38:23 2008 morgan armand
// Last update Mon Aug 11 12:47:36 2008 morgan armand
//

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "Socket.h"
#include "IRunnable.h"

class	Client : public IRunnable
{
public:
  Client(Socket* sck);

  // must be reimplemented. thread main entry point
  void	run();

private:
  Socket*	_sck;
};

#endif // __CLIENT_H__
