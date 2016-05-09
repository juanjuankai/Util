#include "threading.h"
#include <stdio.h>
#include <functional>

using namespace util;

void TestNoArgNoReturn()
{
  printf("start Test\n");
  std::function<void(void)> Func = []() {
    int num = 0;
    for (int i = 0; i < 1000; ++i) {
      num += i;
    }
  };

  ThreadPool pool(4);
  std::vector<std::future<void>> futures;
  for (int i = 0; i < 1000; ++i) {
    futures.push_back(pool.AddTask(Func));
  }

  printf("start ?\n");
  for (auto& future : futures) {
    future.get();
  }
}

void TestArgNoReturn()
{
  std::function<void(int)> Func = [](int num) {
    for (int i = 0; i < 1000; ++i) {
      num += i;
    }
  };

  ThreadPool pool(4);
  std::vector<std::future<void>> futures;

  for (int i = 0; i < 1000; ++i) {
    futures.push_back(pool.AddTask(Func, i));
  }

  for (auto& future : futures) {
    future.get();
  }
}

void TestNoArgReturn()
{
  std::function<int(void)> Func = []() { return 0; };

  ThreadPool pool(4);
  std::vector<std::future<int>> futures;

  for (int i = 0; i < 1000; ++i) {
    futures.push_back(pool.AddTask(Func));
  }

  for (auto& future : futures) {
    future.get();
  }
}


void TestArgReturn()
{
  std::function<int(int)> Func = [](int num) {
    for (int i = 0; i < 100; ++i) {
      num += i;
      printf("%d\n", num);
    }
    return num;
  };

  ThreadPool pool(-1);
  std::vector<std::future<int>> futures;

  for (int i = 0; i < 10; ++i) {
    futures.push_back(pool.AddTask(Func, i));
  }

  for (auto& future : futures) {
    auto result = future.get();
    printf("%d\n", result);
  }
}

void TestStop()
{
  std::function<int(int)> Func = [](int num) {
    for (int i = 0; i < 1000; ++i) {
      num += i;
    }
    return num;
  };

  ThreadPool pool(4);
  std::vector<std::future<int>> futures;

  for (int i = 0; i < 1000; ++i) {
    futures.push_back(pool.AddTask(Func, i));
  }

  //pool.Stop();
  try
  {
  	pool.AddTask(Func, 1000);
  }
  catch (std::runtime_error)
  {
	printf("runtime_error\n");  	
  }

  //BOOST_CHECK_THROW(pool.AddTask(Func, 1000), std::runtime_error);

  pool.Stop();
}

int main()
{
	printf("start main\n");
	//TestNoArgNoReturn();
	TestArgReturn();
	//TestStop();
	return 0;
}
