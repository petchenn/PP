#pragma once
#include <future>
#include "Windows.h"
#include <vector>
#include <iostream>
#include <functional>
#include <queue>
#include <mutex>

class Threads
{
public:

	Threads();
	~Threads();
	void putFunc(std::function<void()>);

private:
	mutable std::mutex m;
	int count;
	std::vector<std::thread> threads;
	//std::thread t;
	//int workcount;
	void work( int j);
	std::queue<std::function<void()>> operations;
	//std::function<void()> curop;
};

