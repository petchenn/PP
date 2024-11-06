// PP2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Threads.h"
#include <chrono>
#include <thread>

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
    std::function<void()> func = printTest;
    tr.putFunc(func);
    func = printHello;
    tr.putFunc(func);
}

// ïåðåäà÷à â êëàññ óêàçàòåëÿ íà ôóíêöèþ, î÷åðåäü ïîòîêîâ, åñëè äðóãèå çàíÿòû.
// ñèíõðîíèçàöèÿ ïîòîêîâ ÷åðåç mutex 
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
