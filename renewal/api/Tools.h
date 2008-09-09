#ifndef _TOOLS_H_
# define _TOOLS_H_

# include "ITools.h"

namespace	ZenZiAPI
{
  class		Tools : public ITools
  {
  public:
    Tools(IMessage& message, IConfig& config, IConnectionInfos& infos);

    IMessage&		message();
    IConfig&		config();
    IConnectionInfos&	connectInfos();
    std::string*	data();
    void		data(std::string* str);

  private:
    IMessage&		_message;
    IConfig&		_config;
    IConnectionInfos&	_cinfos;
    std::string*	_data;
  };
}

#endif // _TOOLS_H_
