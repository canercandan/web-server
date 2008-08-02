//
// HttpConsumer.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:22:30 2008 morgan armand
// Last update Sat Aug  2 11:51:33 2008 caner candan
//

#include <sstream>
#include "HttpConsumer.h"

HttpConsumer::HttpConsumer(HttpProducer* prod)
  : _prod(prod), _start(0), _pos(0)
{}

HttpConsumer::~HttpConsumer()
{}

bool	HttpConsumer::peekChar(char c)
{
  this->giveMeMoreIfntEnough(1);
  return (this->_buf[this->_pos] == c);
}

bool	HttpConsumer::readChar(char c, bool extract /*= false*/)
{
  this->saveStartPos(extract);
  if (this->peekChar(c))
    {
      this->_pos++;
      return (true);
    }
  return (false);
}

bool	HttpConsumer::readRange(char begin, char end, bool extract /*= false*/)
{
  this->saveStartPos(extract);
  this->giveMeMoreIfntEnough(1);
  if (this->_buf[this->_pos] >= begin &&
      this->_buf[this->_pos] <= end)
    {
      this->_pos++;
      return (true);
    }
  return (false);
}

bool	HttpConsumer::readText(char *text, bool extract /*= false*/)
{
  std::string	str(text);

  this->saveStartPos(extract);
  this->giveMeMoreIfntEnough(str.size());
  if (!this->_buf.compare(this->_pos, str.size(), str))
    {
      this->_pos += str.size();
      return (true);
    }
  return (false);
}

bool	HttpConsumer::readInteger(bool extract /*= false*/)
{
  int	i;

  this->saveStartPos(extract);
  for (i = 0; this->readRange('0', '9'); i++);
  return (i > 0);
}

bool	HttpConsumer::readIdentifier(bool extract /*= false*/)
{
  this->saveStartPos(extract);
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

std::string	HttpConsumer::toStr(void)
{
  return (this->_buf.substr(this->_start,
			    this->_pos - this->_start));
}

char	HttpConsumer::toChar(void)
{
  return (this->_buf[this->_start]);
}

int	HttpConsumer::toInt(void)
{
  std::stringstream	ss(this->toStr());
  int			res;

  ss >> res;
  return (res);
}

void	HttpConsumer::giveMeMoreIfntEnough(size_t size)
{
  if (this->_buf.size() <= size)
    this->_buf += this->_prod->nextString();
}

void	HttpConsumer::saveStartPos(bool extract)
{
  if (extract)
    this->_start = this->_pos;
}
