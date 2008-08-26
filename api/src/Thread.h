#ifndef __THREAD_H__
# define __THREAD_H__

# include "IServer.h"
# include "IRunnable.h"

//! Thread
class Thread : public IServer
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
