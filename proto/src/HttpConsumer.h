//
// HttpConsumer.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:20:39 2008 morgan armand
// Last update Sat Aug  2 11:51:44 2008 caner candan
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

  bool	peekChar(char c);

  bool	readChar(char c, bool extract = false);
  bool	readRange(char begin, char end, bool extract = false);
  bool	readText(char *text, bool extract = false);
  bool	readInteger(bool extract = false);
  bool	readIdentifier(bool extract = false);

  std::string	toStr(void);
  char		toChar(void);
  int		toInt(void);

  void	giveMeMoreIfntEnough(size_t size);
  void	saveStartPos(bool extract);
private:
  HttpProducer*	_prod;

  std::string	_buf;
  size_t	_start;
  size_t	_pos;
};

#endif // __HTTP_CONSUMER_H__
