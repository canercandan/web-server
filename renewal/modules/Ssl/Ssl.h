#ifndef __SSL_H__
# define __SSL_H__

# include "IModule.hpp"

using namespace	ZenZiAPI;

class	Ssl : public IModule
{
public:
  typedef std::pair<p_callback, hookPosition>		callback_t;

public:
  Ssl();

  bool	onLoad();
  void	onUnLoad();

  const std::vector<callback_t>&	getCallbacks();

  bool	onAccept(ITools& tools);

private:
  std::vector<callback_t>		_callbacks;
};

#endif // __SSL_H__