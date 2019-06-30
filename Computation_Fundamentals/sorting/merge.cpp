// Sorting Algorithms Source File
// Sort Derived Class -> Merge
// Nick Michael

#include "sort.hpp"
#include <iostream>
#include <cmath>
#include <limits>

// Override Sort Algorithm
size_t Merge::sort()
{
	// Sort Using Recursive Merge Algorithm
	return merge_sort(data, 0, data.size()-1);
}

// Merge Sort Recursive Algorithm
size_t Merge::merge_sort(ivec &v, size_t p, size_t r)
{
	// Initialize Counter
	size_t count = 0;
	if (p < r)
	{
		size_t q = std::floor((p + r)/2);  // Calculate Midpoint
		size_t left = merge_sort(v, p, q); // Sort left of q
		size_t right = merge_sort(v, q+1, r); // Sort right of q
		size_t merger = merge(v, p, q, r); // Merge Algorithm

		// Add Counters from Recursive Steps
		count = left + right + merger;
	}

	// Return Number of Counts
	return count;
}

// Merge Vectors
size_t Merge::merge(ivec &v, size_t p, size_t q, size_t r)
{
	// Initialize New Counter on this Stack Frame
	size_t count = 0;

	// Create Left and Right Vectors
	size_t n1 = q - p + 1;
	size_t n2 = r - q;
	ivec L(n1 + 1, 0);
	ivec R(n2 + 1, 0);

	// Fill Left Vector
	for (size_t k = 0; k < n1; k++)
	{
		L[k] = v[p+k];
		count++; // Increment Counter
	}

	// Fill Right Vector
	for (size_t k = 0; k < n2; k++)
	{
		R[k] = v[q+k+1];
		count++; // Increment Counter
	}

	// Equivalent to Infinity
	L[n1] = std::numeric_limits<int>::max();
	R[n2] = std::numeric_limits<int>::max();

	// Merge Vectors
	size_t i =0, j = 0;
	for (size_t k = p; k < r+1; k++)
	{
		// Increment i if Right Value is Greater
		if (L[i] <= R[j])
		{
			// Pull Value Back into Sorting Vector
			v[k] = L[i];
			i++;
		}

		// Increment j Otherwise
		else
		{
			// Pull Value Back into Sorting Vector
			v[k] = R[j];
			j++;
		}

		// Increment Counter
		count++;
	}

	// Return Counter From Stack Frame
	return count;
}
