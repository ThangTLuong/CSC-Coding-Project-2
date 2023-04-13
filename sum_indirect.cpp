#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

void setup(int64_t size, uint64_t array[])
{
  printf(" inside sum_indirect problem_setup, N=%lld \n", size);

  // Fill array with randomly generated numbers: (0.. size-1) % size... I guess?
  for (int i = 0; i < size; i++)
  {
    array[i] = lrand48() % size;
  }
}

int64_t sum(int64_t size, uint64_t array[])
{
  int64_t sum = 0;
  int64_t index = array[size/2];
  int64_t temp;

  for (int i = 0; i < size; i++)
  {
    temp = array[index];
    sum += temp;
    index = temp;
  }

  return sum;
}
