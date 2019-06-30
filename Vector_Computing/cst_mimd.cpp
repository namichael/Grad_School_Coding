// Multiple Instruction
// Multiple Data (MIMD)
// Nick Michael

#include <chrono>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <thread>

void loop(double *sv, size_t index)
{
	// Set j to fraction of number of threads
	for (size_t j = 0; j < 12500; j++){
		double dj = index + j; // Start from thread based index
		
		for (size_t i = 0; i < 10000; i++){
			double di = i;
			sv[index+j] += di*dj/1000000000.0;
		}

		/* Threads access different parts of array. Should be *
		 * safe  from  data races. Multiple  concurent memory *
		 * accesses  due to cache  line firing should also be *
		 * minimized. Thread start in different memory blocks */
	}
}

int main()
{
	// Initialize Data
	double __attribute((aligned(32))) shared_var[100000];
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

	// Syncronize Threads
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
