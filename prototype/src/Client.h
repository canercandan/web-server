//
// Client.h for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:38:23 2008 morgan armand
// Last update Tue Aug 12 15:05:51 2008 majdi toumi
//

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "Socket.h"
#include "IRunnable.h"
#include "ZiaConfiguration.h"

class				Client : public IRunnable
{
public:
  Client(Socket* sck, const ZiaConfiguration& conf);

  // must be reimplemented. thread main entry point
  void	run();

private:
  Socket*			_sck;
  const ZiaConfiguration&	_conf;
};

#endif // __CLIENT_H__
