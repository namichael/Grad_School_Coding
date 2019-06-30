// Sorting Algorithms Source File
// Sort Derived Class -> Bubble
// Nick Michael

#include "sort.hpp"
#include <iostream>
#include <algorithm>

// Overrided Sort Algorithm
size_t Bubble::sort()
{
	// Create Counter to Count Number of Operations
	size_t count = 0;

	// Sort Using Bubble Sort
	for (size_t i = 0; i < data.size(); i++)
		for (size_t j = 1; j < data.size()-i; j++)
		{
			// Increment Counter
			count++;

			// Exchange if First Value is Greater than Second
			if (data[j] < data[j-1])
				std::swap(data[j], data[j-1]);
		}

	// Return Number of Counts
	return count;
}
