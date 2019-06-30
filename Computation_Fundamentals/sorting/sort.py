#!/usr/bin/python2.6

# Sort From Python
# Nick Michael

import numpy as np
import matplotlib.pyplot as plt
import ctypes as ct
import os

# Get Number of Iterations for Sorting Algorithm
def time_sort(type, local):
	lib_path = os.path.abspath(os.path.join(os.path.dirname(__file__), 'libsort.so'))
	lib = ct.cdll.LoadLibrary(lib_path)

	# Create byte Objects
	b_type = type.encode('utf-8')
	b_local = local.encode('utf-8')

	# C Function
	lib.c_sort.restype = ct.c_int
	lib.c_sort.argtypes = [ ct.c_char_p, ct.c_char_p ]
	return lib.c_sort(b_type, b_local)


class Data:
	def __init__(self):
		self.data = [	'v10_random', 'v100_random', 'v1000_random', 'v10000_random',
						'v10_random_5_values', 'v100_random_5_values', 'v1000_random_5_values',
						'v10000_random_5_values', 'v10_reverse_sorted', 'v100_reverse_sorted',
						'v1000_reverse_sorted', 'v10000_reverse_sorted', 'v10_reverse_sorted_80_percent',
						'v100_reverse_sorted_80_percent', 'v1000_reverse_sorted_80_percent',
						'v10000_reverse_sorted_80_percent', 'v10_sorted', 'v100_sorted',
						'v1000_sorted', 'v10000_sorted', 'v10_sorted_80_percent',
						'v100_sorted_80_percent', 'v1000_sorted_80_percent', 'v10000_sorted_80_percent'	]

		self.sorter = [	'bubble', 'insert', 'merge', 'quick']
		self.results = 0
		self.bubble, self.insert = 0, 0
		self.merge, self.quick = 0, 0

	def getData(self):
		# Initialize Arrays
		self.bubble = np.zeros((len(self.data)/4, 4)).astype(int)
		self.insert = np.zeros((len(self.data)/4, 4)).astype(int)
		self.merge = np.zeros((len(self.data)/4, 4)).astype(int)
		self.quick = np.zeros((len(self.data)/4, 4)).astype(int)
		
		# Get Algorithms Runcounts
		for i in range(len(self.data)/4):
			for j in range(4):
				self.bubble[i, j] = time_sort(self.sorter[0], 'datasets/'+self.data[4*i + j])
				self.insert[i, j] = time_sort(self.sorter[1], 'datasets/'+self.data[4*i + j])
				self.merge[i, j] = time_sort(self.sorter[2], 'datasets/'+self.data[4*i + j])
				self.quick[i, j] = time_sort(self.sorter[3], 'datasets/'+self.data[4*i + j])


def plot(x, y):
	types = ['random', 'random 5', 'reverse', '80% reverse', 'sorted', '80% sorted']
	fig, ax = [], []

	# Bubble Sort
	fig.append(plt.figure())
	ax.append(fig[0].add_subplot(111))

	ax[0].set_xscale('log')
	ax[0].set_yscale('log')
	ax[0].set_title('BubbleSort')
	ax[0].set_xlabel('Vector Size')
	ax[0].set_ylabel('Number of Iterations')
	
	for i in range(6):
		ax[0].plot(x, y.bubble[i, :], label=types[i], lw=2)
	ax[0].legend(loc='upper left')
	fig[0].savefig('Bubble.png')

	# Insertion Sort
	fig.append(plt.figure())
	ax.append(fig[1].add_subplot(111))

	ax[1].set_xscale('log')
	ax[1].set_yscale('log')
	ax[1].set_title('Insertion Sort')
	ax[1].set_xlabel('Vector Size')
	ax[1].set_ylabel('Number of Iterations')

	y.insert[4, :] = 1

	for i in range(6):
		ax[1].plot(x, y.insert[i, :], label=types[i], lw=2)
	ax[1].legend(loc='upper left')
	fig[1].savefig('Insert.png')

	# Merge Sort
	fig.append(plt.figure())
	ax.append(fig[2].add_subplot(111))

	ax[2].set_xscale('log')
	ax[2].set_yscale('log')
	ax[2].set_title('Merge Sort')
	ax[2].set_xlabel('Vector Size')
	ax[2].set_ylabel('Number of Iterations')

	for i in range(6):
		ax[2].plot(x, y.merge[i, :], label=types[i], lw=2)
	ax[2].legend(loc='upper left')
	fig[2].savefig('Merge.png')

	# Merge Sort
	fig.append(plt.figure())
	ax.append(fig[3].add_subplot(111))

	ax[3].set_xscale('log')
	ax[3].set_yscale('log')
	ax[3].set_title('QuickSort')
	ax[3].set_xlabel('Vector Size')
	ax[3].set_ylabel('Number of Iterations')

	for i in range(6):
		ax[3].plot(x, y.quick[i, :], label=types[i], lw=2)
	ax[3].legend(loc='upper left')
	fig[3].savefig('Quick.png')
	
	del fig, ax


def main():
	dat = Data()
	dat.getData()
	x_dat = np.array([10, 100, 1000, 10000])
	plot(x_dat, dat)


if __name__ == "__main__":
	import sys
	main()
