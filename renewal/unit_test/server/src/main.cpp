#include <cppunit/ui/text/TestRunner.h>
#include "ConfigParameter.h"
#include "XmlParserGetter.h"
#include "FileInfoTestFile.h"
#include "FileInfoTestDirectory.h"
#include "FluxStringTest.h"
#include "HttpParserConsume.h"

int	main(void)
{
  CppUnit::TextUi::TestRunner	runner;

  runner.addTest(ConfigParameter::suite());
  runner.addTest(XmlParserGetter::suite());
  runner.addTest(FileInfoTestFile::suite());
  runner.addTest(FileInfoTestDirectory::suite());
  runner.addTest(FluxStringTest::suite());
  runner.addTest(HttpParserConsume::suite());

  runner.run();
  return (0);
}
