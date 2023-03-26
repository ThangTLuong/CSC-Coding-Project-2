#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>



void setup(int64_t size, uint64_t array[]) {
   printf(" inside sum_vector problem_setup, N=%lld \n", size);

   // Fill the array with 0.. size-1
   for (int i = 0; i < size; i++) {
      array[i] = i;
   }
}

int64_t sum(int64_t size, uint64_t array[]) {
   printf(" inside sum_vector perform_sum, N=%lld \n", size);

   int64_t sum = 0;

   for (int i = 0; i < size; i++) {
      sum += array[i];
   }

   return 0;
}

