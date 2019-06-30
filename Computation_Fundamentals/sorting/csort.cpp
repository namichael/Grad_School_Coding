// Execute Sorting Algorithms from Python
// Nick Michael

#include <iostream>
#include <memory>
#include <boost/algorithm/string.hpp>
#include <string>
#include "sort.hpp"

// Enumerated Type
enum class SORTER { BUBBLE, INSERT, MERGE, QUICK, NONE };

// Convert String to Enumerated Type
SORTER Convert(const std::string& str)
{
	if (str == "BUBBLE") return SORTER::BUBBLE;
	else if (str == "INSERT") return SORTER::INSERT;
	else if (str == "MERGE") return SORTER::MERGE;
	else if (str == "QUICK") return SORTER::QUICK;
	else return SORTER::NONE;
}

// C_Sort Function
extern "C" size_t c_sort(const char* alg, const char* file)
{
	// Convert String to Enumerated type and integer
	std::string srt(alg);
	ivec data = load_data(file);
	boost::to_upper(srt);

	// Initialize Counter
	size_t count = 0;

	// Switch Statement for Algorithm
	switch(Convert(srt))
	{
		// bubblesort
		case SORTER::BUBBLE:
			{
				std::unique_ptr<Sort> bubble = std::make_unique<Bubble>(data);
				count = bubble->sort();
			}
			break;

		// Insertion Sort
		case SORTER::INSERT:
			{
				std::unique_ptr<Sort> insert = std::make_unique<Insertion>(data);
				count = insert->sort();
			}
			break;

		// Merge Sort
		case SORTER::MERGE:
			{
				std::unique_ptr<Sort> merge = std::make_unique<Merge>(data);
				count = merge->sort();
			}
			break;

		// quicksort
		case SORTER::QUICK:
			{
				std::unique_ptr<Sort> quick = std::make_unique<Quick>(data);
				count = quick->sort();
			}
			break;

		// Default Case Construct
		default:
			std::cout << "Algorithm Specified Doesn't Exist!" << std::endl;
	}

	// Return Number of Counts
	return count;
}
