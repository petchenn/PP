#pragma once
#include <future>
#include "Windows.h"
#include <vector>
#include <iostream>
#include <functional>
#include <queue>
#include <mutex>
#include <stdio.h>

class Threads
{
public:

	Threads();
	~Threads();
	void putFunc(std::function<void(unsigned int)>);

private:
	mutable std::mutex m;
	int count;
	std::vector<std::thread> threads;
	void work( int j);
	std::queue<std::function<void(unsigned int)>> operations;
	bool workThreads = true;
	unsigned int getThreadID();
};

