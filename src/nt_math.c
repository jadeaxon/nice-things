#include "nt_math.h"

// Recursively calculates the factorial of a number.
long nt_factorial(long n){
	return (n == 0 || n == 1) ? 1 : nt_factorial(n - 1) * n;
}


