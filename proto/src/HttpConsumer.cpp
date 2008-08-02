//
// HttpConsumer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:22:30 2008 morgan armand
// Last update Sat Aug  2 17:38:55 2008 caner candan
//

#include <sstream>
#include <iostream>
#include "HttpConsumer.h"

HttpConsumer::HttpConsumer(HttpProducer* prod)
  : _prod(prod), _pos(0)
{}

HttpConsumer::~HttpConsumer()
{}

void	HttpConsumer::appendBuf(size_t size)
{
  if (this->_buf.size() <= size)
    this->_buf += this->_prod->nextString();
}

bool	HttpConsumer::peekChar(char c)
{
  this->appendBuf(1);
  return (this->_buf[this->_pos] == c);
}

bool	HttpConsumer::readChar(char c)
{
  if (!this->peekChar(c))
    return (false);
  this->_pos++;
  return (true);
}

bool	HttpConsumer::readChar(char c, char& c_r)
{
  if (!this->readChar(c))
    return (false);
  c_r = this->_buf[this->_pos - 1];
  return (true);
}

bool	HttpConsumer::readRange(char c_start, char c_end)
{
  this->appendBuf(1);
  if (this->_buf[this->_pos] < c_start ||
      this->_buf[this->_pos] > c_end)
    return (false);
  this->_pos++;
  return (true);
}

bool	HttpConsumer::readRange(char c_start, char c_end, char& c_r)
{
  if (!this->readRange(c_start, c_end))
    return (false);
  c_r = this->_buf[this->_pos - 1];
  return (true);
}

bool	HttpConsumer::readText(const std::string& s)
{
  this->appendBuf(s.size());
  if (this->_buf.compare(this->_pos, s.size(), s))
    return (false);
  this->_pos += s.size();
  return (true);
}

bool	HttpConsumer::readText(const std::string& s, std::string& s_r)
{
  unsigned int	start = this->_pos;

  if (!this->readText(s))
    return (false);
  s_r = this->_buf.substr(start, this->_pos - start);
  return (true);
}

bool	HttpConsumer::readInteger(void)
{
  int	i;

  for (i = 0; this->readRange('0', '9'); i++);
  return (i > 0);
}

bool	HttpConsumer::readInteger(int& i_r)
{
  unsigned int	start = this->_pos;
  std::stringstream	ss;

  if (!this->readInteger())
    return (false);
  ss.str(this->_buf.substr(start, this->_pos - start));
  ss >> i_r;
  return (true);
}

bool	HttpConsumer::readIdentifier(void)
{
  if (!this->readRange('a', 'z') &&
      !this->readRange('A', 'Z') &&
      !this->readChar('_'))
    return (false);
  while (this->readRange('0', '9') ||
	 this->readRange('a', 'z') ||
	 this->readRange('A', 'Z') ||
	 this->readChar('_'));
  return (true);
}

bool	HttpConsumer::readIdentifier(std::string& i_r)
{
  unsigned int	start = this->_pos;

  if (!this->readIdentifier())
    return (false);
  i_r = this->_buf.substr(start, this->_pos - start);
  return (true);
}
