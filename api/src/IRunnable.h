#ifndef __IRUNNABLE_H__
# define __IRUNNABLE_H__

# include "IServer.h"

//! IRunnable
class IRunnable : public IServer
{
public:
  virtual ~IRunnable(){};

  virtual void run() = 0;
};

#endif // !__IRUNNABLE_H__
