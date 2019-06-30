// Single Instruction
// Multiple Threads (SIMT)
// Nick Michael

#include <chrono>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <immintrin.h>
#include <thread>

void loop(double *sv, size_t index)
{
	// Vector of divisor value from serial algorithm
	__m256d dvec = _mm256_set1_pd(1000000000);
	for (size_t j = 0; j < 3125; j++)
	{
		// Account for both vectorization and parallelization
		__m256d val = _mm256_load_pd(sv + index + 4*j);
		__m256d jvec = _mm256_set_pd(index + 4*j, index + 4*j+1,
				index + 4*j+2, index + 4*j+3);

		// Only load 4 memory values into registers for each processor
		__m256d dval = _mm256_div_pd(jvec, dvec);
		for (size_t i = 0; i < 2000; i++)
		{
			__m256d ivec[5];
			for (size_t k = 0; k < 5; k++)
				ivec[k] = _mm256_set1_pd(5*i + k);
			
			for (size_t k = 0; k < 5; k++)
				val = _mm256_fmadd_pd(ivec[k], dval, val);
		}
		_mm256_store_pd(sv + index + 4*j, val);
	}
}

int main()
{
	// Initialize Data
	double __attribute__((aligned(32))) shared_var[100000];
	std::fill(shared_var, shared_var + 100000, 0.0);
	
	// Start Timer
	auto start = std::chrono::high_resolution_clock::now();

	// Create Threads
	std::thread t_1(loop, shared_var, 12500);
	std::thread t_2(loop, shared_var, 25000);
	std::thread t_3(loop, shared_var, 37500);
	std::thread t_4(loop, shared_var, 50000);
	std::thread t_5(loop, shared_var, 62500);
	std::thread t_6(loop, shared_var, 75000);
	std::thread t_7(loop, shared_var, 87500);

	// Run Function on Main Thread
	loop(shared_var, 0);

	// Synchronize Threads
	t_1.join();
	t_2.join();
	t_3.join();
	t_4.join();
	t_5.join();
	t_6.join();
	t_7.join();

	// Stop Timer
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_time = end - start;

	// Print Time
	std::cout << "\nElapsed Time: " << elapsed_time.count();
	std::cout << " seconds\n" << std::endl;
}
