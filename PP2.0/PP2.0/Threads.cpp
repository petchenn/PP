#include "Threads.h"

Threads::Threads() {
	count = std::thread::hardware_concurrency();
	//workcount = 0;
	for (int i = 0; i < count; i++) {
		std::thread t(&Threads::work, this, i);
		threads.push_back( std::move(t));
	}
	std::cout << threads.size() << ' ' << count;
}

Threads::~Threads() {
	for (int i = 0; i < count; i++) {
		threads[i].join();
	}
}

void Threads::work(int j) {
	while (true) {
		std::function<void()> curop;
	{
		std::lock_guard<std::mutex> guard(m);
		printf(" %d worked. ", j);
		//std::cout << j << "worked ";
		if (operations.empty()) { continue; }

		curop = operations.front(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		operations.pop();
	}
		curop();
		
	}
}

void Threads::putFunc(std::function<void()> op) {
	std::lock_guard<std::mutex> guard(m);
	operations.push(op);
}
