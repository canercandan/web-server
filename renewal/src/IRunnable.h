#ifndef __IRUNNABLE_H__
# define __IRUNNABLE_H__

class	IRunnable
{
public:
  virtual ~IRunnable(){};

  virtual void run() = 0;
};

#endif // !__IRUNNABLE_H__
