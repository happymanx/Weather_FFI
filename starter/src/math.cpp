//
// Created by HappyBoy on 2022/3/26.
//
#include <iostream>
using namespace std;

extern "C"
int get_sum(int a, int b)
{
    return a + b;
}

extern "C"
double get_cpp_number()
{
  return 1234567.0f;
}
