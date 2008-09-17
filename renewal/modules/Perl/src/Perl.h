#ifndef __PERL_H__
# define __PERL_H__

# include "IModule.hpp"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# else
#  define EXPORT
#endif

class	Perl : public ZenZiAPI::IModule
{
  typedef std::pair<p_callback, ZenZiAPI::hookPosition>	pairCallback;
  typedef std::vector<pairCallback>			listCallback;
public:
  Perl();
  ~Perl();

  bool	onLoad();
  void	onUnLoad();

  const listCallback&	getCallbacks();

  bool	run(ZenZiAPI::ITools&);
private:
  listCallback	_listCallback;
};

#endif // !__PERL_H__
