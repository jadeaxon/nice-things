#include "nt_error.h"

#include <stdio.h> // puts()

void main(void) {
	int retval = 0;
	nt_error(retval, "Failed to set variable to zero");
	puts("PASS");
	retval = -1;
	nt_error(retval, "Simulated error");
	// The program should exit now.
	puts("FAIL");

}


