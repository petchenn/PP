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
		
		std::lock_guard<std::mutex> guard(m);
		std::cout << j << "worked ";
		if (!operations.empty()) {
			std::function<void()> curop;
			
			curop = operations.front(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			operations.pop();
			curop();
		}
	}
}

void Threads::putFunc(std::function<void()> op) {
	operations.push(op);
}