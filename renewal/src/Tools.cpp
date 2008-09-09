#include "Tools.h"

Tools::Tools(IMessage& message, IConfig& config, IConnectionInfos& infos)
  : _message(message), _config(config), _cinfos(cinfos)
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
