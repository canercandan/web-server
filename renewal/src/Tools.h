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
