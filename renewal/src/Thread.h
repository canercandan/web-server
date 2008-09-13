#ifndef __THREAD_H__
# define __THREAD_H__

# ifdef WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
# else
#  include <pthread.h>
# endif

# include "IRunnable.h"

class Thread
{
public:
  Thread(IRunnable& run);

  void	start();
private:
# ifdef WIN32
  static DWORD WINAPI	_threadProc(LPVOID arg);
# else
  static void*	_threadProc(void* arg);
# endif
private:
  IRunnable&	_obj;
#ifdef WIN32
  HANDLE	_thread;
#else
  pthread_t	_thread;
#endif
};

#endif // !__THREAD_H__
