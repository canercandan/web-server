//
// HttpConsumer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 15:10:07 2008 morgan armand
// Last update Wed Aug 13 16:40:08 2008 caner candan
//

#include <sstream>
#include "HttpConsumer.h"

HttpConsumer::HttpConsumer(HttpProducer* prod)
  : _prod(prod), _cur_pos(0), _old_pos(0)
{}

HttpConsumer::~HttpConsumer()
{}

std::string	HttpConsumer::getBuf()
{
  return (this->_buf.substr(this->_cur_pos));
}

void	HttpConsumer::consume()
{
  this->_buf.erase(0, this->_cur_pos);
  this->_cur_pos = 0;
}

void	HttpConsumer::prepare()
{
  this->_ext_pos = this->_cur_pos;
}

void	HttpConsumer::extract(std::string& s_r)
{
  s_r = this->_buf.substr(this->_ext_pos,
			  this->_cur_pos - this->_ext_pos);
  this->_ext_pos = 0;
}

std::string	HttpConsumer::extract()
{
  std::string	res;

  res = this->_buf.substr(this->_ext_pos,
			  this->_cur_pos - this->_ext_pos);
  this->_ext_pos = 0;
  return (res);
}

void	HttpConsumer::save()
{
  this->_old_pos = this->_cur_pos;
}

void	HttpConsumer::back()
{
  this->_cur_pos = this->_old_pos;
}

bool	HttpConsumer::peekChar(const char c)
{
  this->_appendBuf(1);
  return (this->_buf[this->_cur_pos] == c);
}

bool	HttpConsumer::readChar(const char c)
{
  if (!this->peekChar(c))
    return (false);
  this->_cur_pos++;
  return (true);
}

bool	HttpConsumer::readChar(const char c, char &c_r)
{
  if (!this->readChar(c))
    return (false);
  c_r = this->_buf[this->_cur_pos - 1];
  return (true);
}

bool	HttpConsumer::peekRange(const char c_start, const char c_end)
{
  this->_appendBuf(1);
  return (this->_buf[this->_cur_pos] > c_start &&
	  this->_buf[this->_cur_pos] < c_end);
}

bool	HttpConsumer::readRange(const char c_start, const char c_end)
{
  if (!this->peekRange(c_start, c_end))
    return (false);
  this->_cur_pos++;
  return (true);
}

bool	HttpConsumer::readRange(const char c_start, const char c_end, char& c_r)
{
  if (!this->peekRange(c_start, c_end))
    return (false);
  c_r = this->_buf[this->_cur_pos - 1];
  return (true);
}

bool	HttpConsumer::readText(const std::string& s)
{
  size_t	size;

  size = s.size();
  this->_appendBuf(size);
  if (this->_buf.compare(this->_cur_pos, size, s))
    return (false);
  this->_cur_pos += size;
  return (true);
}

bool	HttpConsumer::readText(const std::string& s, std::string& s_r)
{
  size_t	pos;

  pos = this->_cur_pos;
  if (!this->readText(s))
    return (false);
  s_r = this->_buf.substr(pos, this->_cur_pos - pos);
  return (true);
}

bool	HttpConsumer::readInteger()
{
  int	i;

  i = 0;
  while (this->readRange('0', '9'))
    i++;
  return (i > 0);
}

bool	HttpConsumer::readInteger(int& i_r)
{
  size_t		pos;
  std::stringstream	ss;

  pos = this->_cur_pos;
  if (!this->readInteger())
    return (false);
  ss.str(this->_buf.substr(pos, this->_cur_pos - pos));
  ss >> i_r;
  return (true);
}


bool	HttpConsumer::readIdentifier()
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

bool	HttpConsumer::readIdentifier(std::string& s_r)
{
  size_t	pos = this->_cur_pos;

  if (!this->readIdentifier())
    return (false);
  s_r = this->_buf.substr(pos, this->_cur_pos - pos);
  return (true);
}

void	HttpConsumer::_appendBuf(size_t size)
{
  while (this->_buf.substr(this->_cur_pos).size() < size)
    this->_buf += this->_prod->nextString();
}
