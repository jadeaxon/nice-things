#include "nt_string.h"

#include <stdio.h>
#include <string.h>

// Tests the functions declared in nt_string.h.
int main(void) {
	char s[] = "A string\nto chomp\n\r";
	char e[] = "A string\nto chomp";
	nt_chomp(s);
	// printf("'%s'\n", s);	
	if (strcmp(s, e) == 0) {
		puts("PASS");
	}
	else {
		puts("FAIL");
	}

	char s2[] = "Just a string with a newline\n";
	char e2[] = "Just a string with a newline";
	nt_chomp(s2);
	if (strcmp(s2, e2) == 0) {
		puts("PASS");
	}
	else {
		puts("FAIL");
	}

	char s3[] = "String to chop";
	char e3[] = "String to cho";
	nt_chop(s3);
	if (strcmp(s3, e3) == 0) {
		puts("PASS");
	}
	else {
		puts("FAIL");
	}

} // main()


