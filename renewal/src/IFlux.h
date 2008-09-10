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
