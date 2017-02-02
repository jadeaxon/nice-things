#include "nt_math.h"

#include <stdlib.h> // exit()
#include <stdio.h> // printf()

// Recursively calculates the factorial of a number.
long nt_factorial(long n){
	if ((n >= 21) || (n < 0)) {
		printf("ERROR: Arg %ld is out of range 0-20.\n", n);
		exit(1);
	}

	return (n == 0 || n == 1) ? 1 : nt_factorial(n - 1) * n;
}


