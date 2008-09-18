#ifndef __PHP_H__
# define __PHP_H__

# include "IModule.hpp"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# else
#  define EXPORT
# endif

class	Php : public ZenZiAPI::IModule
{
  typedef std::pair<p_callback, ZenZiAPI::hookPosition>	pairCallback;
  typedef std::vector<pairCallback>			listCallback;
public:
  Php();
  ~Php();

  bool	onLoad();
  void	onUnLoad();

  const listCallback&	getCallbacks();

  bool	run(ZenZiAPI::ITools&);
private:
  listCallback	_listCallback;
};

#endif // !__PHP_H__
