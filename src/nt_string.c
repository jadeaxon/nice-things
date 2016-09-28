#include <stdio.h>
#include <string.h>

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


// Reverses the given null-terminated string.  Mutates the given string.
// There's no strrev() in Linux string.h even though some docs mention it online.
char* nt_strrev(char* str) {
    if (str) {
        char* end = str + strlen(str) - 1;

        // Walk inwards from both ends of the string, 
        // swapping until we get to the middle
        while (str < end) {
            NT_XOR_SWAP(*str, *end);
            str++;
            end--;
        }
    }
} // nt_strrev()

