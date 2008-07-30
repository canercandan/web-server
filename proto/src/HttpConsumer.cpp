//
// HttpConsumer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:22:30 2008 morgan armand
// Last update Wed Jul 30 19:35:27 2008 morgan armand
//

#include "HttpConsumer.h"

HttpConsumer::HttpConsumer(HttpProducer& prod)
  : _prod(&prod), _buff()
{
}
