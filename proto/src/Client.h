//
// Client.h for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 21:38:23 2008 morgan armand
// Last update Tue Aug  5 10:21:49 2008 morgan armand
//

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "IRunnable.h"

#include "Parser.h"
#include "HttpRequest.h"
#include "HttpProducer.h"
#include "HttpConsumer.h"

class	Client : public IRunnable
{
public:
  Client(Socket* sck);

  // must be reimplemented. thread main entry point
  void	run();

private:
  Socket*	_sck;
  HttpRequest*	_request;
  HttpProducer*	_producer;
  HttpConsumer*	_consumer;
};

#endif // __CLIENT_H__
