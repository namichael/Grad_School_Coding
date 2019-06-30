// Single Instruction
// Multiple Data (SIMD)
// Nick Michael

#include <chrono>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <immintrin.h>

void loop(double *sv)
{
	// Vector of divisor value from serial algorithm
	__m256d dvec = _mm256_set1_pd(1000000000);
	for (size_t j = 0; j < 25000; j++)
	{
		// Divide Problem by 4 for AVX2 Double Precision
		__m256d val = _mm256_load_pd(sv + 4*j); // Load 4 Memory Values
		__m256d jvec = _mm256_set_pd(4*j, 4*j+1, 4*j+2, 4*j+3);
		
		// Load 4 incrementing j values and perform division
		__m256d dval = _mm256_div_pd(jvec, dvec);
		for (size_t i = 0; i < 2000; i++)
		{
			__m256d ivec[5]; // Pre-load multiple AVX2 registers
			for (size_t k = 0; k < 5; k++)
				ivec[k] = _mm256_set1_pd(5*i + k);
			
			for (size_t k = 0; k < 5; k++)
				// Perform vector multiplication and perform +=
				val = _mm256_fmadd_pd(ivec[k], dval, val);
		}
		// Store register values back to memory
		_mm256_store_pd(sv + 4*j, val);
	}
}

int main()
{
	// Initialize Data
	double __attribute__((aligned(32))) shared_var[100000];
	std::fill(shared_var, shared_var + 100000, 0.0);

	// Run Function on Main Thread
	auto start=	std::chrono::high_resolution_clock::now();
	loop(shared_var);
	auto end =	std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_time = end - start;

	// Print Time
	std::cout << "\nElapsed Time: " << elapsed_time.count();
	std::cout << " seconds\n" << std::endl;
}
