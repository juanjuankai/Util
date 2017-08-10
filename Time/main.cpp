#include <iostream>
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
}
