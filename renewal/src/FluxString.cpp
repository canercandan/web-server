//
// FluxString.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Fri Sep 12 18:54:30 2008 caner candan
// Last update Fri Sep 12 19:16:42 2008 caner candan
//

#include "FluxString.h"

FluxString::FluxString(const std::string& string)
  : _string(string)
{}

FluxString::~FluxString()
{}

FluxString::FluxString(const FluxString& fluxstring)
  : IFlux()
{*this = fluxstring;}

FluxString&	FluxString::operator=(const FluxString& fluxstring)
{
  if (this != &fluxstring)
    {
      this->_string = fluxstring._string;
    }
  return (*this);
}

std::string	FluxString::nextString()
{
  std::string	res(this->_string);

  this->_string.clear();
  return (res);
}
