// Execute Sorting Algorithms
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

// Main Function
int main(int argc, char* argv[])
{
	// Convert String to Enumerated type and integer
	std::string srt(argv[1]);
	ivec data = load_data(argv[2]);
	boost::to_upper(srt);

	// Switch Statement for Algorithm
	switch(Convert(srt))
	{
		// bubblesort
		case SORTER::BUBBLE:
			{
				std::unique_ptr<Sort> bubble = std::make_unique<Bubble>(data);
				std::cout << bubble->sort() << std::endl;
				assert_sorted(bubble->getData());
			}
			break;

		// Insertion Sort
		case SORTER::INSERT:
			{
				std::unique_ptr<Sort> insert = std::make_unique<Insertion>(data);
				std::cout << insert->sort() << std::endl;
				assert_sorted(insert->getData());
			}
			break;

		// Merge Sort
		case SORTER::MERGE:
			{
				std::unique_ptr<Sort> merge = std::make_unique<Merge>(data);
				std::cout << merge->sort() << std::endl;
				assert_sorted(merge->getData());
			}
			break;

		// quicksort
		case SORTER::QUICK:
			{
				std::unique_ptr<Sort> quick = std::make_unique<Quick>(data);
				std::cout << quick->sort() << std::endl;
				assert_sorted(quick->getData());
			}
			break;

		// Default Case Construct
		default:
			std::cout << "Algorithm Specified Doesn't Exist!" << std::endl;
	}

	return 0;
}
