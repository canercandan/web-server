#ifndef __AUTOINDEX_H__
# define __AUTOINDEX_H__

# include "IModule.hpp"
# include "FileInfo.h"
# include "URIParser.h"

class	AutoIndex : public ZenZiAPI::IModule
{
  typedef std::pair<p_callback, ZenZiAPI::hookPosition>	pairCallback;
  typedef std::vector<pairCallback>			listCallback;
public:
  AutoIndex();
  ~AutoIndex();

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

#endif // !__AUTOINDEX_H__
