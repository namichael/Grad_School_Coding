// Sorting Algorithms Source File
// Sort Base Class
// Nick Michael

#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

// Overload << Operator
std::ostream &operator<<(std::ostream &os, const Sort &so)
{
	// Print all Variables to Standard Output
	for (size_t i = 0; i < so.data.size(); i++)
		os << so.data[i] << std::endl;

	// Return Stream Variable
	return os;
}

// Get Data
ivec Sort::getData() const
{
	return data;
}

// Data Loader
ivec load_data(const char* file)
{
	// Initialize Line Counter
	size_t count = 0;

	// Create Stack for First Run Through File
	{
		// Open File for Counting
		int line;
		std::ifstream fcount;
		fcount.open(file);

		// Count the Number of Lines in File
		while (fcount >> line)
			count++;

		// Close File
		fcount.close();
	}

	// Load Data Into Vector
	ivec data(count, 0);
	{
		std::ifstream infile;
		infile.open(file);
		for (size_t k = 0; k < count; k++)
			infile >> data[k];
		infile.close();
	}

	// Return Data Vector
	return data;
}

void assert_sorted(const ivec &v)
{
	for (size_t k = 0; k < v.size() - 1; k++)
		assert(v[k] <= v[k+1]);
}
