#include <stdio.h>

#include "nt_string.h"


// Removes the last character of a string.  Mutates the given string.
// Returns the given string.
char* nt_chop(char* s) {
	char* s0 = s;
	if (*s == '\0') return s0; // Handle null string.
	while (*s++ != '\0'); // Find end of string.
	s -= 2;
	*s = '\0';
	return s0;
} // nt_chop() 


// Removes all trailing newlines from a string.  Mutates the given string.
// Returns the given string.
char* nt_chomp(char* s) {
	char* s0 = s;
	if (*s == '\0') return s0; // Handle null string.
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
	return s0;
} // nt_chomp()


