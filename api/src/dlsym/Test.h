#ifndef __TEST_H__
# define __TEST_H__

class	ITest
{
public:
  virtual ~ITest(){}

  virtual int	getA() = 0;
  virtual int	getB() = 0;
};

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
