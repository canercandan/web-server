#ifndef	__CONNECTIONINFOS_H__
# define __CONNECTIONINFOS_H__

# include "IConnectionInfos.hpp"

namespace	ZenZiAPI
{
  class		ConnectionInfos : public IConnectionInfos
  {
  public:
    ConnectionInfos(SOCKET sck);

    const SOCKET		getSocket() const;
    const connectionType	getConnectType(void) const;
    Extension*			getExtension(void) const;
    void			setExtension(void *ptr);

  private:
    connectionType	_connectionType;
    Extension*		_extension;
    SOCKET		_sck;
  };
}

#endif	// !__CONNECTIONINFOS_H__
