//
// FluxString.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Fri Sep 12 18:51:55 2008 caner candan
// Last update Fri Sep 12 18:57:12 2008 caner candan
//

#ifndef __FLUXSTRING__
# define __FLUXSTRING__

# include <string>
# include "IFlux.h"

class	FluxString : public IFlux
{
public:
  FluxString(const std::string&);
  ~FluxString();
  FluxString(const FluxString&);
  FluxString&	operator=(const FluxString&);

  std::string	nextString();
private:
  std::string	_string;
};

#endif // !__FLUXSTRING__
