// Sorting Algorithms Source File
// Sort Derived Class -> Insertion
// Nick Michael

#include "sort.hpp"
#include <iostream>

// Override Sort Algorithm
size_t Insertion::sort()
{
	// Initialize Counter
	size_t count = 0;

	// Sort Using Insertion Sort
	for (size_t k = 1; k < data.size(); k++)
	{
		// Create Key for Insertion Comparrison
		int key = data[k];
		size_t l = k - 1; // Decrementer

		// Decrement Array Until Correct Point is Reached
		while (l >= 0 && data[l] > key)
		{
			data[l+1] = data[l];
			l--; //decrement
			count++; // increment counter
		}
		
		// Set Data Point equal to key
		data[l+1] = key;
	}

	// Return Number of Counts
	return count;
}
