#include "Tools.h"

using namespace	ZenZiAPI;

Tools::Tools(SOCKET sck)
  : _cinfos(sck)
{
}

IMessage&		Tools::message()
{
  return (this->_message);
}

IConfig&		Tools::config()
{
  return (this->_config);
}

IConnectionInfos&	Tools::connectInfos()
{
  return (this->_cinfos);
}

std::string*		Tools::data()
{
  return (this->_data);
}

void			Tools::data(std::string* str)
{
  this->_data = str;
}
