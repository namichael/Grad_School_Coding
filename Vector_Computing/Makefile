# Makefile
# Nick Michael

compile: cst_sisd.cpp cst_mimd.cpp cst_simd.cpp cst_simt.cpp
	@echo 'COMPILING'
	@g++ -c cst_sisd.cpp -O0 -o cst_sisd.o
	@g++ -c cst_mimd.cpp -O0 -o cst_mimd.o
	@g++ -c cst_simd.cpp -mavx2 -march=native -O0 -o cst_simd.o
	@g++ -c cst_simt.cpp -mavx2 -march=native -O0 -o cst_simt.o

build: cst_sisd.o cst_mimd.o cst_simd.o cst_simt.o
	@echo 'BUILDING'
	@g++ cst_sisd.o -o run_cst_sisd
	@g++ cst_mimd.o -pthread -o run_cst_mimd
	@g++ cst_simd.o -o run_cst_simd
	@g++ cst_simt.o -pthread -o run_cst_simt

clean:
	@echo 'CLEANING'
	@rm *.o
