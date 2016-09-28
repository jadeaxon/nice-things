#include <stdio.h>

#include "nt_string.h"

void nt_foo(void) {
	;
}

// Removes all trailing newlines from a string.  Mutates the given string.
// Returns the given string.
char* nt_chomp(char* s) {
	while (*s++ != '\0'); // Find end of string.
	s -= 2;
	char c = '\0';
	while  (c = *s) {
		if ((c == '\n') || (c == '\r')) {
			*s = '\0';
		}
		else { // Not a newline character.
			break;
		}
		s--;
	} // next char at end of string
} // nt_chomp()


