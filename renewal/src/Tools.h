//
// Tools.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 22:23:01 2008 caner candan
// Last update Sat Sep 13 22:23:02 2008 caner candan
//

#ifndef _TOOLS_H_
# define _TOOLS_H_

# include "ITools.hpp"
# include "Config.h"
# include "Message.h"
# include "ConnectionInfos.h"

class	Tools : public ZenZiAPI::ITools
{
public:
  Tools(SOCKET sck);

  ZenZiAPI::IMessage&		message();
  ZenZiAPI::IConfig&		config();
  ZenZiAPI::IConnectionInfos&	connectInfos();

  std::string*	data();
  void		data(std::string* str);
private:
  Message		_message;
  Config&		_config;
  ConnectionInfos	_cinfos;
  std::string*		_data;
};

#endif // _TOOLS_H_
