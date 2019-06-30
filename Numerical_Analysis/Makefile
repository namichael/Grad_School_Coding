# Makefile
# Nick Michael

CXX = g++ -Wall -O3
FORT = gfortran -Ofast

fcompile: farray.f90
	$(FORT) -c farray.f90

ccompile: farray.cpp
	$(CXX) -c farray.cpp

fexecutable:
	$(FORT) -o farray farray.o

cexecutable:
	$(CXX) -o carray farray.o

clean:
	rm *.o

fall: fcompile fexecutable clean
call: ccompile cexecutable clean