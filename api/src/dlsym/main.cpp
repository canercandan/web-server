#include <dlfcn.h>
#include <iostream>
#include "ITest.h"

typedef ITest*	(*fct)();

static void	error()
{
  std::cout << "err: " << ::dlerror() << std::endl;
  exit(-1);
}

int		main(void)
{
  void*		handle;
  fct		func;
  ITest*	test;

  if (!(handle = ::dlopen("./test.so", RTLD_LAZY)))
    error();
  if (!(func = (fct)::dlsym(handle, "call")))
    error();
  test = func();
  std::cout << "a: " << test->getA() << std::endl;
  std::cout << "b: " << test->getB() << std::endl;
  ::dlclose(handle);
  return (0);
}
