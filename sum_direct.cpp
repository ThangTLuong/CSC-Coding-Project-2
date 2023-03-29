#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

// Leave as is
void setup(int64_t size, uint64_t array[])
{
   printf(" inside direct_sum problem_setup, N=%lld \n", size);
}

int64_t sum(int64_t size, uint64_t array[])
{
   printf(" inside direct_sum perform_sum, N=%lld \n", size);

   int64_t sum = 0;

   for (int i = 0; i < size; i++)
   {
      sum += i;
   }

   return sum;
}
