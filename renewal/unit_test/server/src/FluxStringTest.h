#ifndef __FLUXSTRINGTEST_H__
# define __FLUXSTRINGTEST_H__

# include <string>
# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>
# include "FluxString.h"

class	FluxStringTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(FluxStringTest);
  CPPUNIT_TEST(testNextString);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testNextString();
private:
  std::string	_message;
  FluxString*	_flux;
};

#endif // !__FLUXSTRINGTEST_H__
