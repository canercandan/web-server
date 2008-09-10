#ifndef	__CONNECTIONINFOS_H__
# define __CONNECTIONINFOS_H__

# include "IConnectionInfos.hpp"

using namespace ZenZiAPI;

class	ConnectionInfos : public IConnectionInfos
{
public:
  const SOCKET		socket();
  const connectionType	connectType(void);
  Extension*		extension(void);
  void			extension(void *ptr);

private:
  connectionType	_connectionType;
  Extension*		_extension;
};

#endif	// !__CONNECTIONINFOS_H__
