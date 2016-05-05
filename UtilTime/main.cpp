/*#include <iostream>
#include "timer.h"

using namespace util;

void TestDefault()
{
	Timer timer;
	std::cout << "TestDefault" << std::endl;
	std::cout << (timer.ElapsedMicroSeconds() == 0) << std::endl;
	std::cout << (timer.ElapsedSeconds() == 0) << std::endl;
	std::cout << (timer.ElapsedMinutes() == 0) << std::endl;
	std::cout << (timer.ElapsedHours() == 0) << std::endl;
	std::cout << "TestDefault end" << std::endl;
}

void TestPause()
{
	std::cout << "TestPause" << std::endl;
	Timer timer;
	timer.Start(); 
	timer.Pause();
	double prev_time = timer.ElapsedMicroSeconds();
	for (size_t i = 0; i < 5; ++i) {
		std::cout << prev_time << std::endl;
		prev_time = timer.ElapsedMicroSeconds();
	}
	timer.Resume();
	for (size_t i = 0; i < 5; ++i) {
		std::cout << prev_time << std::endl;
		timer.PrintMicroSeconds();
		prev_time = timer.ElapsedMicroSeconds();
	}
	timer.Reset();
	std::cout << (timer.ElapsedMicroSeconds() == 0) << std::endl;
	std::cout << "TestPause end" << std::endl;
}

int main()
{
	TestDefault();
	TestPause();
	return 0;
}*/
/*
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE "timer"
#include <boost/test/unit_test.hpp>

#include <vector>

#include "timer.h"

using namespace util;

BOOST_AUTO_TEST_CASE(TestDefault) {
  Timer timer;
  BOOST_CHECK_EQUAL(timer.ElapsedMicroSeconds(), 0);
  BOOST_CHECK_EQUAL(timer.ElapsedSeconds(), 0);
  BOOST_CHECK_EQUAL(timer.ElapsedMinutes(), 0);
  BOOST_CHECK_EQUAL(timer.ElapsedHours(), 0);
}

BOOST_AUTO_TEST_CASE(TestStart) {
  Timer timer;
  timer.Start();
  BOOST_CHECK_GE(timer.ElapsedMicroSeconds(), 0);
  BOOST_CHECK_GE(timer.ElapsedSeconds(), 0);
  BOOST_CHECK_GE(timer.ElapsedMinutes(), 0);
  BOOST_CHECK_GE(timer.ElapsedHours(), 0);
}

BOOST_AUTO_TEST_CASE(TestPause) {
  Timer timer;
  timer.Start();
  timer.Pause();
  double prev_time = timer.ElapsedMicroSeconds();
  for (size_t i = 0; i < 1000; ++i) {
    BOOST_CHECK_EQUAL(timer.ElapsedMicroSeconds(), prev_time);
    prev_time = timer.ElapsedMicroSeconds();
  }
  timer.Resume();
  for (size_t i = 0; i < 1000; ++i) {
    BOOST_CHECK_GE(timer.ElapsedMicroSeconds(), prev_time);
  }
  timer.Reset();
  BOOST_CHECK_EQUAL(timer.ElapsedMicroSeconds(), 0);
}
*/
