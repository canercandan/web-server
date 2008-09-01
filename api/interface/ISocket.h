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
    virtual bool	create() = 0;
    //! undef
    virtual bool	bind(const int port) = 0;
    //! undef
    virtual bool	listen(const int backlog) = 0;
    //! undef
    virtual ISocket*	accept() = 0;
    //! undef
    virtual void	close() = 0;
    //! undef
    virtual int		recv(char* buf, int len) = 0;
    //! undef
    virtual int		send(std::string& buf) = 0;
    //! undef
    virtual bool	isValid() = 0;
  };
};

#endif // !__ISOCKET_H__
