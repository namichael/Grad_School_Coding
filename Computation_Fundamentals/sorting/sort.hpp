// Sorting Algorithms Header
// Nick Michael

#include <vector>
#include <iostream>

typedef std::vector<int> ivec;

// Parent Sorting Class
class Sort
{
  protected:
		ivec data;

  public:
		// Initialize Sorting Vector
		Sort(){}
		Sort(ivec dat) : data(dat){}
		virtual ~Sort(){};

		// Sort Data
		virtual size_t sort() = 0;

		// Return Data
		friend std::ostream &operator<<(std::ostream&, const Sort&);
		ivec getData() const;
};

// Bubble Child of Sort
class Bubble : public Sort
{
  public:
		// Initialize Bubble Sort
		Bubble(ivec dat) : Sort(dat){}
		~Bubble(){};

		// Sort Using Bubble Sort
		size_t sort() override;
};

// Insertion Child of Sort
class Insertion : public Sort
{
  public:
		// Initialize Insertion Sort
		Insertion(ivec dat) : Sort(dat){}
		~Insertion(){};

		// Sort Data
		size_t sort() override;
};

// Merge Child of Sort
class Merge : public Sort
{
  private:
		// Merge Sort Recursive Algorithms
		size_t merge_sort(ivec&, size_t, size_t);
		size_t merge(ivec&, size_t, size_t, size_t);

  public:
		// Initialize Merge Sort
		Merge(ivec dat) : Sort(dat){}
		~Merge(){};

		// Sort Data
		size_t sort() override;
};

// Quick Child of Sort
struct qstruct{ size_t q, count; };
class Quick : public Sort
{
  private:
		// Quick Sort Recursive Algorithms
		size_t quicksort(ivec&, int, int);
		qstruct partition(ivec&, int, int);

  public:
		// Initialize Quicksort
		Quick(ivec dat) : Sort(dat){}
		~Quick(){};

		// Sort Data
		size_t sort() override;
};

// Data Loader and Sort Checker
ivec load_data(const char*);
void assert_sorted(const ivec&);
