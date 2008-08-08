//
// HttpConsumer.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:20:39 2008 morgan armand
// Last update Fri Aug  8 10:43:57 2008 morgan armand
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

  std::string	getBuf(void);

  void	appendBuf(unsigned int size);

  void		consume();
  std::string	extract(int pos);

  unsigned int	getPos() const;
  void		setPos(unsigned int pos);

  bool	eof();

  bool	peekChar(const char c);

  bool	readChar(const char c);
  bool	readChar(const char c, char& c_r);

  bool	readRange(const char c_start, const char c_end);
  bool	readRange(const char c_start, const char c_end, char& c_r);

  bool	readText(const std::string& s);
  bool	readText(const std::string& s, std::string& s_r);

  bool	readInteger();
  bool	readInteger(int& i_r);

  bool	readIdentifier();
  bool	readIdentifier(std::string& i_r);
private:
  HttpProducer*	_prod;

  std::string	_buf;
  unsigned int	_pos;
  unsigned int	_deep;
};

#endif // __HTTP_CONSUMER_H__
