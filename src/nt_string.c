#include "nt_string.h"

#include <stdio.h>
#include <string.h>


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


// Keeps only chars in s that exist in keepers.  Deletes all other characters.
// Mutates the given string and returns it.
char* nt_keep_chars(char* s, char* keepers) {
	const int D = 0;	
	D && printf("+nt_keep_chars(%s, %s)\n", s, keepers);
	char* i = s;
	char* s0 = s;
	while (*s != '\0') {
		char c = *s;
		char* k = keepers;
		D && printf("Checking %c\n", c);
		while ( *k != '\0') {
			D && printf("  %c == %c?\n", c, *k);
			if (c == *k) {
				*i = c;
				i++;
				break;
			}
			k++;
		} // next keeper char
		s++;
	} // next string char
	*i = '\0';
	D && printf("-nt_keep_chars(%s, %s)\n", s0, keepers);
	return s0;
} // nt_keep_chars()


