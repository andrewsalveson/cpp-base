#if !defined(TEST_MAIN_H)
#define TEST_MAIN_H 

#include <iostream>
#include <string>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestRunner.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>

#define HOWDY  "Hello, world."

#include "../src/Speaker.h"

class SpeakerTestCase : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(SpeakerTestCase);
    CPPUNIT_TEST(speakTest);
  CPPUNIT_TEST_SUITE_END();
  
  public:
    void setUp(void);
    void tearDown(void);

  protected:
    void speakTest(void);

  private:
    Speaker *fixture;

};

void SpeakerTestCase::speakTest()
{
  CPPUNIT_ASSERT(HOWDY == fixture->speak());
}

void SpeakerTestCase::setUp()
{
  fixture = new Speaker();
}

void SpeakerTestCase::tearDown()
{
  delete fixture;
  fixture = NULL;
}

CPPUNIT_TEST_SUITE_REGISTRATION( SpeakerTestCase );

int main()
{
  // informs test listener about results
  CPPUNIT_NS::TestResult testResult;

  // register listener for collecting results
  CPPUNIT_NS::TestResultCollector collectedResults;
  testResult.addListener(&collectedResults);

  // register listener for per-test progress
  CPPUNIT_NS::BriefTestProgressListener progress;
  testResult.addListener(&progress);

  // insert test suite at test runner by registry
  CPPUNIT_NS::TestRunner testRunner;
  testRunner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  testRunner.run( testResult );

  // output results
  CPPUNIT_NS::CompilerOutputter compilerOutputter( &collectedResults, std::cerr );
  compilerOutputter.write();

  return collectedResults.wasSuccessful() ? 0 : 1;
}

#endif
