//
// HttpConsumer.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 15:07:41 2008 morgan armand
// Last update Wed Aug 13 11:42:58 2008 morgan armand
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

  std::string getBuf();

  void	consume();

  void	prepare();

  void		extract(std::string& s_r);
  std::string	extract();

  void	save();
  void	back();

  bool	peekChar(const char c);
  bool	readChar(const char c);
  bool	readChar(const char c, char& c_r);

  bool	peekRange(const char c_start, const char c_end);
  bool	readRange(const char c_start, const char c_end);
  bool	readRange(const char c_start, const char c_end, char& c_r);

  bool	readText(const std::string& s);
  bool	readText(const std::string& s, std::string& s_r);

  bool	readInteger();
  bool	readInteger(int& i_r);

  bool	readIdentifier();
  bool	readIdentifier(std::string& s_r);

private:
  void	_appendBuf(size_t size);

private:
  HttpProducer*	_prod;

  std::string	_buf;
  size_t	_cur_pos;
  size_t	_old_pos;
  size_t	_ext_pos;
};

#endif // !__HTTP_CONSUMER_H__
