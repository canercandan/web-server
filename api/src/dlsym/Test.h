#ifndef __TEST_H__
# define __TEST_H__

# include "ITest.h"

class	Test : public ITest
{
public:
  Test(int a, int b);

  virtual int	getA();
  virtual int	getB();
private:
  int	_a;
  int	_b;
};

#endif // !__TEST_H__
