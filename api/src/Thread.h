#ifndef __THREAD_H__
# define __THREAD_H__

# ifdef WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
# else
#  include <pthread.h>
# endif

# include "IRoot.h"
# include "IRunnable.h"

namespace	ziApi
{
  //! Thread
  class Thread : public IRoot
  {
  public:
    //! undef
    //! \param run a IRunnable pointer
    Thread(IRunnable* run);

    //! undef
    void	start();
  private:
# ifdef WIN32
    static DWORD WINAPI	_threadProc(LPVOID arg);
# else
    static void*	_threadProc(void* arg);
# endif
  private:
    pthread_t	pthread;
  };
};

#endif // !__THREAD_H__
