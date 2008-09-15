#ifndef __PERL_H__
# define __PERL_H__

#include <string>
#include "IModule.hpp"

class Perl : public ZenZiAPI::IModule
{
  typedef std::vector<std::pair<p_callback, ZenZiAPI::hookPosition> >	listCallback;
public:
  Perl();
  bool	onLoad();
  void	onUnLoad();

  const listCallback&	getCallbacks();

  bool	run(ZenZiAPI::ITools&);

private:
  listCallback	_p_int;
};

#endif // !__PERL_H__
