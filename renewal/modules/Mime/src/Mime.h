#ifndef __MIME_H__
# define __MIME_H__

# include "IModule.hpp"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# else
#  define EXPORT
# endif

class	Mime : public ZenZiAPI::IModule
{
  typedef std::pair<p_callback, ZenZiAPI::hookPosition>	pairCallback;
  typedef std::vector<pairCallback>			listCallback;
public:
  Mime();
  ~Mime();

  bool	onLoad();
  void	onUnLoad();

  const listCallback&	getCallbacks();

  bool	run(ZenZiAPI::ITools&);
private:
  listCallback	_listCallback;
};

#endif // !__MIME_H__
