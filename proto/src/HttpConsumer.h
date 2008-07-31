//
// HttpConsumer.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:20:39 2008 morgan armand
// Last update Wed Jul 30 20:16:27 2008 morgan armand
//

#ifndef __HTTP_CONSUMER_H__
#define __HTTP_CONSUMER_H__

#include <string>
#include "HttpProducer.h"

class	HttpConsumer
{
public:
  HttpConsumer(HttpProducer* prod);

private:
  HttpProducer*	_prod;
  std::string	_buff;
};

#endif // __HTTP_CONSUMER_H__
