#include "nt_crypt.h"

#include <stdio.h>
#include <string.h>


// Tests the functions declared in nt_crypt.h.
int main(void) {
	puts("nt_xor_crypt()");
	char s[] = "Secret message";
	char e[] = "Secret message";
	nt_xor_crypt(s, 'C');
	(strcmp(s, e) != 0) ? puts("PASS") : puts("FAIL");
	nt_xor_crypt(s, 'C');
	(strcmp(s, e) == 0) ? puts("PASS") : puts("FAIL");

} // main()


