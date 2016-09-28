#include "nt_string.h"

#include <stdio.h>
#include <string.h>

int main(void) {
	char s[] = "A string\nto chomp\n\r";
	char e[] = "A string\nto chomp";
	nt_foo();	
	nt_chomp(s);
	printf("'%s'\n", s);	
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

} // main()


