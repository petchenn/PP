#include "Threads.h"

Threads::Threads() {
	count = std::thread::hardware_concurrency();
	workThreads = true;
	for (int i = 0; i < count; i++) {
		std::thread t(&Threads::work, this, i+50);
		threads.push_back( std::move(t));
	}
}

Threads::~Threads() {
	workThreads = false;
	for (int i = 0; i < count; i++) {
		if(threads[i].joinable())
			threads[i].join();
	}
}

void Threads::work(int j) {
	while (workThreads) {
		std::function<void()> curop;
		{
			std::lock_guard<std::mutex> guard(m);

			//printf("%d  ", getThreadID());
			if (operations.empty()) { continue; }

			curop = std::bind(operations.front(), getThreadID()); 
			operations.pop();
		}
		curop();
	}
}

void Threads::putFunc(std::function<void(unsigned int)> op) {
	std::lock_guard<std::mutex> guard(m);
	operations.push(op);
}

unsigned int Threads::getThreadID() {
	std::thread::id threadID = std::this_thread::get_id();
	unsigned int v = *static_cast<unsigned int*>(static_cast<void*>(&threadID));
	return v;
}
