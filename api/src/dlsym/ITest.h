#ifndef __ITEST_H__
# define __ITEST_H__

class	ITest
{
public:
  virtual ~ITest(){}

  virtual int	getA() = 0;
  virtual int	getB() = 0;
};

#endif // !__ITEST_H__
