#ifndef __IMODULE_H__
# define __IMODULE_H__

# include "IRoot.h"
# include "IRequest.h"
# include "IResponse.h"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# endif

namespace	ZapII
{
  class	IRequest;
  class	IResponse;

  //! IModule
  class	IModule : public IRoot
  {
  public:
    enum	State	{CONTINUE, BREAK, STOP, ERROR};
    enum	Event	{PRE, POST, END, ERROR};

    virtual ~IModule(){}

    //! undef
    virtual State	affect(const Event&, IRequest* request) = 0;
    //! undef
    virtual State	affect(const Event&, IResponse* response) = 0;
  };
};

#endif // !__IMODULE_H__
