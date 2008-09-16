//
// Tools.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 22:22:44 2008 caner candan
// Last update Tue Sep 16 17:46:54 2008 caner candan
//

#include "Tools.h"

Tools::Tools(SOCKET sck, const std::string& type)
  : _config(*Config::getInstance()), _cinfos(sck, type),
    _data(NULL)
{}

ZenZiAPI::IMessage&	Tools::message()
{
  return (this->_message);
}

ZenZiAPI::IConfig&	Tools::config()
{
  return (this->_config);
}

ZenZiAPI::IConnectionInfos&	Tools::connectInfos()
{
  return (this->_cinfos);
}

std::string*	Tools::data()
{
  return (this->_data);
}

void	Tools::data(std::string* str)
{
  this->_data = str;
}
