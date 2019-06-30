// Single Instruction
// Single Data (SISD)
// Nick Michael

#include <chrono>
#include <algorithm>
#include <iomanip>
#include <iostream>

void loop(double *sv)
{
	// Made up algorithm
	for (size_t j = 0; j < 100000; j++){
		double dj = j;
		
		// Multiple iterations create longer measurable times
		for (size_t i = 0; i < 10000; i++){
			double di = i;
			sv[j] += di*dj/1000000000.0;
		}
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