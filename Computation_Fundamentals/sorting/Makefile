# Make
# Sorting Algorithms
# Nick Michael

# Flags
CXX=g++
CXXFLAGS=-fPIC -Wall -Wpedantic -O2
WORK=/home/nam75/Work/School/Grad/Fall_2018/Intro_Computation/HWS5
LDFLAGS=-Wl,-rpath=$(WORK)
LINK=-L$(WORK)


# Executable
sort: main.o libsort.so
	$(CXX) $(LINK) $(LDFLAGS) -o sort main.o -lsort


# Object Files
compile: sort.cpp bubble.cpp insert.cpp merge.cpp quick.cpp csort.cpp
	$(CXX) $(CXXFLAGS) -c sort.cpp -o sort.o
	$(CXX) $(CXXFLAGS) -c bubble.cpp -o bubble.o
	$(CXX) $(CXXFLAGS) -c insert.cpp -o insert.o
	$(CXX) $(CXXFLAGS) -c merge.cpp -o merge.o
	$(CXX) $(CXXFLAGS) -c quick.cpp -o quick.o
	$(CXX) $(CXXFLAGS) -c csort.cpp -o csort.o


# Shared Object
share: sort.o bubble.o insert.o merge.o quick.o csort.o
	$(CXX) -shared sort.o bubble.o insert.o merge.o quick.o csort.o -o libsort.so


# Main File
main: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


# Clean Object Files
clean:
	rm *.o
