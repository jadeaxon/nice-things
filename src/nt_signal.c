#include "nt_signal.h"

#include <signal.h> // sigaction(), sigemptyset(), struct sigaction, SIGINT, etc.
#include <stdlib.h> // NULL


// Registers a signal handler for the given signal.
// Returns -1 if it fails.
//
// Use nt_register_signal_handler(SIGINT, SIG_DFL) to restore default handler.
int nt_register_signal_handler(int signal, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(signal, &action, NULL);
}

