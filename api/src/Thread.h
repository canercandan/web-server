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
  void*	_threadProc(void* arg);
private:
  pthread_t	pthread;
};

#endif // !__THREAD_H__
