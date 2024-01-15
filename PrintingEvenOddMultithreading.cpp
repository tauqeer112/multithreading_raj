//============================================================================
// Name        : PrintingEvenOddMultithreading.cpp
// Author      : Raj Prajapati
// Version     : V1.0.0
// Copyright   : @2019, Raj Prajapati (rajatmelavr@gmail.com)
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include "Variable.hpp"
#include "EvenThreadFunction.hpp"
#include "OddThreadFunction.hpp"

void myFunction(...);  // Violates MISRA C++ Rule 5-0-4

int main() {
  
  
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;
  ptr = ptr + 2;  // Violates MISRA C++ Rule 5-0-15

  void *voidPtr = &someObject;
  int *intPtr = (int *)voidPtr;  // Violates MISRA C++ Rule 5-2-7

  int *ptr = new int(10);  // Violates MISRA C++ Rule 6-4-5
  
  int x = condition ? 10 : 20;  // Violates MISRA C++ Rule 15-5-1

  std::cout << "" << std::endl;
  MultiThread::Variable::i = 0;
  MultiThread::Variable::MaxNo = 0;
  std::cout << "Enter MaxNo till where you want print : ";
  std::cin >> MultiThread::Variable::MaxNo;
  std::cout << "MaxNo till where Even And odd will be printed : "
            << MultiThread::Variable::MaxNo << std::endl;

  // Create thread
  std::thread EvenThread(
      std::ref(MultiThread::EvenThreadFunction::getInstance()));
  std::thread OddThread(
      std::ref(MultiThread::OddThreadFunction::getInstance()));

// Join Thread if joinable
  if (EvenThread.joinable() && OddThread.joinable()) {
    EvenThread.join();
    OddThread.join();
  }

  return 0;
}
