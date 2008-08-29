#ifndef __IRUNNABLE_H__
# define __IRUNNABLE_H__

# include "IRoot.h"

namespace	ziApi
{
  //! IRunnable
  class IRunnable : public IRoot
  {
  public:
    virtual ~IRunnable(){};

    //! undef
    virtual void run() = 0;
  };
};

#endif // !__IRUNNABLE_H__
