#include "nt_string.h"

#include <stdio.h>
#include <string.h>

// Tests the functions declared in nt_string.h.
int main(void) {
	puts("nt_chomp()");
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

	puts("nt_chop()");
	char s3[] = "String to chop";
	char e3[] = "String to cho";
	nt_chop(s3);
	if (strcmp(s3, e3) == 0) {
		puts("PASS");
	}
	else {
		puts("FAIL");
	}

	puts("nt_strrev()");
	char s4[] = "Reverse me!";
	char e4[] = "!em esreveR";
	nt_strrev(s4);
	if (strcmp(s4, e4) == 0) {
		puts("PASS");
	}
	else {
		puts("FAIL");
	}

	char s5[] = "Even";
	char e5[] = "nevE";
	nt_strrev(s5);
	if (strcmp(s5, e5) == 0) {
		puts("PASS");
	}
	else {
		puts("FAIL");
	}

} // main()


