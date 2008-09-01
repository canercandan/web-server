#ifndef __ISOCKET_H__
# define __ISOCKET_H__

# include <string>
# include "IRoot.h"

namespace	ziApi
{
  //! ISocket
  class	ISocket : public IRoot
  {
  public:
    virtual ~ISocket() {};

    //! undef
    virtual bool	create();
    //! undef
    virtual bool	bind(const int port);
    //! undef
    virtual bool	listen(const int backlog);
    //! undef
    virtual ISocket*	accept();
    //! undef
    virtual void	close();
    //! undef
    virtual int		recv(char* buf, int len);
    //! undef
    virtual int		send(std::string& buf);
    //! undef
    virtual bool	isValid();
  };
};

#endif // !__ISOCKET_H__
