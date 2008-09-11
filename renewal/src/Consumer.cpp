//
// Consumer.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:40 2008 caner candan
// Last update Thu Sep 11 11:50:56 2008 morgan armand
//

#include <sstream>
#include "Consumer.h"

Consumer::Consumer(IFlux& flux)
  : _flux(flux), _ext_pos(0), _cur_pos(0), _old_pos(0)
{}

std::string	Consumer::getBuf()
{
  return (this->_buf.substr(this->_cur_pos));
}

void	Consumer::consume()
{
  this->_buf.erase(0, this->_cur_pos);
  this->_cur_pos = 0;
}

void	Consumer::prepare()
{
  this->_ext_pos = this->_cur_pos;
}

void	Consumer::extract(std::string& s_r)
{
  s_r = this->_buf.substr(this->_ext_pos,
			  this->_cur_pos - this->_ext_pos);
  this->_ext_pos = 0;
}

std::string	Consumer::extract()
{
  std::string	res;

  res = this->_buf.substr(this->_ext_pos,
			  this->_cur_pos - this->_ext_pos);
  this->_ext_pos = 0;
  return (res);
}

void	Consumer::save()
{
  this->_old_pos = this->_cur_pos;
}

void	Consumer::back()
{
  this->_cur_pos = this->_old_pos;
}

bool	Consumer::peekChar(const char c)
{
  this->_appendBuf(1);
  return (this->_buf[this->_cur_pos] == c);
}

bool	Consumer::readChar(const char c)
{
  if (!this->peekChar(c))
    return (false);
  this->_cur_pos++;
  return (true);
}

bool	Consumer::readChar(const char c, char &c_r)
{
  if (!this->readChar(c))
    return (false);
  c_r = this->_buf[this->_cur_pos - 1];
  return (true);
}

bool	Consumer::peekRange(const char c_start, const char c_end)
{
  this->_appendBuf(1);
  return (this->_buf[this->_cur_pos] >= c_start &&
	  this->_buf[this->_cur_pos] <= c_end);
}

bool	Consumer::readRange(const char c_start, const char c_end)
{
  if (!this->peekRange(c_start, c_end))
    return (false);
  this->_cur_pos++;
  return (true);
}

bool	Consumer::readRange(const char c_start, const char c_end, char& c_r)
{
  if (!this->peekRange(c_start, c_end))
    return (false);
  c_r = this->_buf[this->_cur_pos - 1];
  return (true);
}

bool	Consumer::readText(const std::string& s)
{
  size_t	i;
  size_t	size;

  size = s.size();
  this->save();
  for (i = 0; i < size; i++)
    {
      if (!this->readChar(s.at(i)))
	{
	  this->back();
	  return (false);
	}
    }
  return (true);
}

bool	Consumer::readText(const std::string& s, std::string& s_r)
{
  size_t	pos;

  pos = this->_cur_pos;
  if (!this->readText(s))
    return (false);
  s_r = this->_buf.substr(pos, this->_cur_pos - pos);
  return (true);
}

bool	Consumer::readInteger()
{
  int	i;

  i = 0;
  while (this->readRange('0', '9'))
    i++;
  return (i > 0);
}

bool	Consumer::readInteger(int& i_r)
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

bool	Consumer::readInteger(std::string& s_r)
{
  size_t		pos;
  std::stringstream	ss;

  pos = this->_cur_pos;
  if (!this->readInteger())
    return (false);
  ss.str(this->_buf.substr(pos, this->_cur_pos - pos));
  ss >> s_r;
  return (true);
}

bool	Consumer::readIdentifier()
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

bool	Consumer::readIdentifier(std::string& s_r)
{
  size_t	pos = this->_cur_pos;

  if (!this->readIdentifier())
    return (false);
  s_r = this->_buf.substr(pos, this->_cur_pos - pos);
  return (true);
}

void	Consumer::_appendBuf(size_t size)
{
  std::string	s;

  while (this->_buf.substr(this->_cur_pos).size() < size)
    {
      s = this->_flux.nextString();

      if (s.empty())
	break;

      this->_buf += s;
    }
}
