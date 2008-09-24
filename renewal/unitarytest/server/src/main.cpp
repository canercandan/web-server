#include <cppunit/ui/text/TestRunner.h>
#include "ConfigParameter.h"

int	main(void)
{
  CppUnit::TextUi::TestRunner	runner;

  runner.addTest(ConfigParameter::suite());

  runner.run();
  return (0);
}
