//
// Consumer.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:48 2008 caner candan
// Last update Thu Sep 11 11:49:46 2008 morgan armand
//

#ifndef __CONSUMER_H__
# define __CONSUMER_H__

# include <string>
# include "IFlux.h"

class	Consumer
{
public:
  Consumer(IFlux& flux);

  std::string	getBuf();

  void	consume();
  void	prepare();

  void	extract(std::string& s_r);
  std::string	extract();

  void	save();
  void	back();

  bool	readChar(const char c);
  bool	readChar(const char c, char& c_r);
  bool	peekChar(const char c);

  bool	readRange(const char c_start, const char c_end);
  bool	readRange(const char c_start, const char c_end, char& c_r);
  bool	peekRange(const char c, const char c_r);

  bool	readText(const std::string& s);
  bool	readText(const std::string& s, std::string& s_r);

  bool	readInteger();
  bool	readInteger(int& i_r);
  bool	readInteger(std::string& s_r);

  bool	readIdentifier();
  bool	readIdentifier(std::string& s_r);
private:
  void	_appendBuf(size_t size);
private:
  IFlux&	_flux;
  std::string	_buf;
  size_t	_ext_pos;
  size_t	_cur_pos;
  size_t	_old_pos;
};

#endif // !__CONSUMER_H__
