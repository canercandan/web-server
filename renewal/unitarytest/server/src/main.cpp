#include <cppunit/ui/text/TestRunner.h>
#include "ConfigParameter.h"
#include "XmlParserGetter.h"
#include "FileInfoTest.h"

int	main(void)
{
  CppUnit::TextUi::TestRunner	runner;

  runner.addTest(ConfigParameter::suite());
  runner.addTest(XmlParserGetter::suite());
  runner.addTest(FileInfoTest::suite());

  runner.run();
  return (0);
}
