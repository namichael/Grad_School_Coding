# Recursive Step Problem


def recurse_step(n):
	if n and n - 1:
		return recurse_step(n-1) + recurse_step(n-2)
	else:
		return 1


def main(n):
	print recurse_step(n)


if __name__ == "__main__":
	import sys
	main(int(sys.argv[1]))

