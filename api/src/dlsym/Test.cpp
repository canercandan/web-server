#include "Test.h"

Test::Test(int a, int b)
  : _a(a), _b(b)
{}

int	Test::getA()
{
  return (this->_a);
}

int	Test::getB()
{
  return (this->_b);
}

extern "C"
{
  Test*	call()
  {
    return (new Test(1, 2));
  }
}
