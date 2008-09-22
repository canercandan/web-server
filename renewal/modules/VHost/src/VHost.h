#ifndef __VHOST_H__
# define __VHOST_H__

# include "IModule.hpp"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# else
#  define EXPORT
# endif

class	VHost : public ZenZiAPI::IModule
{
  typedef std::pair<p_callback, ZenZiAPI::hookPosition>	pairCallback;
  typedef std::vector<pairCallback>			listCallback;
public:
  VHost();
  ~VHost();

  bool	onLoad();
  void	onUnLoad();

  const listCallback&	getCallbacks();

  bool	run(ZenZiAPI::ITools&);
private:
  listCallback	_listCallback;
};

#endif // !__VHOST_H__
