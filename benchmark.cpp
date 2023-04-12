//
// (C) 2022, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

using namespace std;

/* The benchmarking program */
int main(int argc, char **argv)
{
  cout << fixed << setprecision(10);

#define MAX_PROBLEM_SIZE 1 << 28 //  256M
  vector<int64_t> problem_sizes{1000000, MAX_PROBLEM_SIZE};

  vector<uint64_t> array(MAX_PROBLEM_SIZE);

  int64_t total;
  int n_problems = problem_sizes.size();

  /* For each test size */
  for (int64_t size : problem_sizes)
  {
    printf("Working on problem size N=%lld \n", size);

    // invoke user code to set up the problem
    setup(size, &array[0]);
    int32_t numberOfLoops = 0;

    chrono::time_point<chrono::high_resolution_clock> start_time;
    chrono::time_point<chrono::high_resolution_clock> end_time;
    chrono::duration<double> elapsed;


    start_time = chrono::high_resolution_clock::now();
    while (elapsed.count() < 30.00) {
      // invoke method to perform the sum
      total = sum(size, &array[0]);
      end_time = chrono::high_resolution_clock::now();
      elapsed = end_time - start_time;
      numberOfLoops++;
    }

    // insert your end timer code here, and print out elapsed time for this problem size
     
    cout << " Total number of time sum() was called: " << numberOfLoops << "\n"
    << " Elapsed time is : " << elapsed.count() << endl;

    printf(" Sum result = %lld \n", total);

  } // end loop over problem sizes
}

// EOF
