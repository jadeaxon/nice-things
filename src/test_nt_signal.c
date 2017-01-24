#include "nt_signal.h"

#include <stdio.h> // puts()
#include <stdlib.h> // exit()
#include <unistd.h> // sleep()


// Handles SIGINT.
void sigint_handler(int signal) {
	static int count = 0;
	count++;
	if (count == 3) {
		exit(1);
	}
}

// Registers SIGINT handler.
void main(void) {
	nt_register_signal_handler(2, sigint_handler);
	puts("Press ^C three times to exit.");
	while (1) {
		sleep(100);
	}
}


