/**
 * @file Thread.h
 * @brief 
 * @note 
 */
class Thread 
{
public:
  Thread (IRunnable* );
  void start ();
private:
  void* _threadProc (void* arg);
  pthread_t ;
};
