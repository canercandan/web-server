#ifndef __ISOCKET_H__
# define __ISOCKET_H__

//! ISocket
class ISocket 
{
public:
  virtual ~ISocket();

  virtual bool		create() = 0;
  virtual ISocket*	accept() = 0;
  virtual void		close() = 0;
};

#endif // !__ISOCKET_H__
