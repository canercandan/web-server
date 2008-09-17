#ifndef __PERL_H__
# define __PERL_H__

# include "IModule.hpp"
# include "FileInfo.h"
# include "URIParser.h"

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
  std::string	_listingDirectory(ZenZiAPI::ITools&,
				  FileInfo&, URIParser&);
private:
  listCallback	_listCallback;
};

#endif // !__PERL_H__
