// Sorting Algorithms Source File
// Sort Derived Class -> Quick
// Nick Michael

#include "sort.hpp"
#include <iostream>
#include <algorithm>

// Override Sort Algorithm
size_t Quick::sort()
{
	// Sort Using Recurssive Quicksort
	return quicksort(data, 0, data.size()-1);
}

// Quicksort Recursive Algorithm
size_t Quick::quicksort(ivec &v, int p, int r)
{
	// Initialize Counter on Stack Frame
	size_t count = 0;

	// Run quicksort on Left and Right of Vector
	if (p < r)
	{
		qstruct part = partition(v, p, r);	// Return Struct with q and counter
		size_t left = quicksort(v, p, part.q-1); // left quicksort
		size_t right = quicksort(v, part.q+1, r); // right quicksort

		// Add Counts from Recursive Steps
		count = part.count + left + right;
	}

	// Return Count from Stack Frame
	return count;
}

// Quicksort Partition
qstruct Quick::partition(ivec &v, int p, int r)
{
	// Initialize Pivot
	qstruct part = {0, 0};
	const int x = v[r];
	int i = p - 1;

	// Move Data About Pivot
	for (size_t j = p; j < static_cast<size_t>(r); j++)
	{
		// Swap Values if j Value is Less than or Equal to Pivot
		if (v[j] <= x)
		{
			i++;
			if (i != static_cast<int>(j)) std::swap(v[i], v[j]);
		}

		// Increment Counter
		part.count++;
	}

	// Swap Pivot with i+1 Value
	std::swap(v[i+1], v[r]);
	part.q = i + 1;

	// Return q and counter
	return part;
}
