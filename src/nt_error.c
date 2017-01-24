#include "nt_error.h"

#include <string.h> // strerror()
#include <stdio.h> // fprintf()
#include <stdlib.h> // exit()
#include <errno.h> // errno

// Checks a system call for error.  Writes custom message to stderr and exits if error.
void nt_error(int retval, char* msg) {
	if (retval != -1) return;
	fprintf(stderr, "ERROR: %s: %s\n", msg, strerror(errno));
	exit(1);
}


