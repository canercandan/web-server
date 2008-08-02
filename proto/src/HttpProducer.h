//
// HttpProducer.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:05:57 2008 morgan armand
// Last update Wed Jul 30 22:35:30 2008 caner candan
//

#ifndef __HTTP_PRODUCER_H__
# define __HTTP_PRODUCER_H__

# include <string>
# include "Socket.h"

class	HttpProducer
{
public:
  // Default constructor. Use the given socket to read data.
  HttpProducer(Socket* sck);
  ~HttpProducer();

  // Return a new std::string containing data
  std::string	nextString(void);

private:
  Socket*	_sck;
};

#endif // __HTTP_PRODUCER_H__
