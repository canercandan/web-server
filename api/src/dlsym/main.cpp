#include <dlfcn.h>
#include <iostream>
#include "Test.h"

typedef Test*	(*fct)();

int		main(void)
{
  void*		handle;
  fct		func;
  ITest*	test;

  if (!(handle = ::dlopen("./Test.so", RTLD_LAZY)))
    {
      std::cout << "err: " << ::dlerror() << std::endl;
      return (-1);
    }
  if (!(func = (fct)::dlsym(handle, "call")))
    {
      std::cout << "err: " << ::dlerror() << std::endl;
      return (-1);
    }
  test = func();
  std::cout << "a: " << test->getA() << std::endl;
  std::cout << "b: " << test->getB() << std::endl;
  ::dlclose(handle);
  return (0);
}
