//
// IFlux.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 22:19:56 2008 caner candan
// Last update Sat Sep 13 22:19:56 2008 caner candan
//

#ifndef __IFLUX_H__
# define __IFLUX_H__

# include <string>

class	IFlux
{
public:
  virtual ~IFlux(){}

  virtual std::string	nextString() = 0;
};

#endif // !__IFLUX_H__
