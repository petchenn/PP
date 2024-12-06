// PP2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Threads.h"
#include <chrono>
#include <thread>

int k;
std::mutex m;

void BigAndHeavyOperation(unsigned int n) {
    auto start = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::milliseconds(5000); // 5 секунд

    double result = 0.0;
    for (long long i = 0; i < 1e9; ++i) {
        result += sqrt(i);

        // Проверяем, прошло ли 5 секунд
        if (std::chrono::high_resolution_clock::now() - start > duration) {
            break;
        }
    }

  
    k++;

    printf("result : %f \n", result);
  
}

void printTest() {
    printf( "test \n");
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

void printHello() {
    printf( "hello\n");
    std::this_thread::sleep_for(std::chrono::seconds(5));
}


int main()
{
    Threads tr;
    std::function<void(unsigned int)> f = BigAndHeavyOperation;
    tr.putFunc(f);
    tr.putFunc(f);
    tr.putFunc(f);
    while (k < 3) {
        
    }
}

