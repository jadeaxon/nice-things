#include "nt_math.h"

#include <stdio.h> // puts()

int main(void) {
	puts("nt_factorial()");
	long v, e, r;

	v = 1; e = 1;
	r = nt_factorial(v);
	(r == e) ? puts("PASS") : puts("FAIL");

	v = 2; e = 2;
	r = nt_factorial(v);
	(r == e) ? puts("PASS") : puts("FAIL");

	v = 5; e = 120;
	r = nt_factorial(v);
	(r == e) ? puts("PASS") : puts("FAIL");

	v = 10; e = 3628800;
	r = nt_factorial(v);
	(r == e) ? puts("PASS") : puts("FAIL");

	/* 21 clocks the long range on my desktop.
	r = nt_factorial(20);
	printf("%ld\n", r);

	r = nt_factorial(21);
	printf("%ld\n", r);
	*/

	// r = nt_factorial(-1); // Errors out and exits.
	// r = nt_factorial(21); // Errors out and exits.

	return 0;
}


