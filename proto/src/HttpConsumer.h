//
// HttpConsumer.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:20:39 2008 morgan armand
// Last update Sat Aug  2 16:30:16 2008 caner candan
//

#ifndef __HTTP_CONSUMER_H__
#define __HTTP_CONSUMER_H__

#include <string>
#include "HttpProducer.h"

class	HttpConsumer
{
public:
  HttpConsumer(HttpProducer* prod);
  ~HttpConsumer();

  void	appendBuf(unsigned int size);

  bool	peekChar(char c);

  bool	readChar(char c);
  bool	readChar(char c, char& c_r);

  bool	readRange(char c_start, char c_end);
  bool	readRange(char c_start, char c_end, char& c_r);

  bool	readText(const std::string& s);
  bool	readText(const std::string& s, std::string& s_r);

  bool	readInteger(void);
  bool	readInteger(int& i_r);

  bool	readIdentifier(void);
  bool	readIdentifier(std::string& i_r);
private:
  HttpProducer*	_prod;

  std::string	_buf;
  unsigned int	_pos;
};

#endif // __HTTP_CONSUMER_H__
