#include "nt_string.h"

#include <stdio.h>
#include <string.h>

void test__nt_keep_chars(void);
void test__nt_starts_with(void);


// Tests the functions declared in nt_string.h.
int main(void) {
	puts("nt_chomp()");
	char s[] = "A string\nto chomp\n\r";
	char e[] = "A string\nto chomp";
	nt_chomp(s);
	(strcmp(s, e) == 0) ? puts("PASS") : puts ("FAIL");

	char s2[] = "Just a string with a newline\n";
	char e2[] = "Just a string with a newline";
	nt_chomp(s2);
	(strcmp(s2, e2) == 0) ? puts("PASS") : puts ("FAIL");

	puts("nt_chop()");
	char s3[] = "String to chop";
	char e3[] = "String to cho";
	nt_chop(s3);
	(strcmp(s3, e3) == 0) ? puts("PASS") : puts ("FAIL");

	puts("nt_strrev()");
	char s4[] = "Reverse me!";
	char e4[] = "!em esreveR";
	nt_strrev(s4);
	(strcmp(s4, e4) == 0) ? puts("PASS") : puts ("FAIL");

	char s5[] = "Even";
	char e5[] = "nevE";
	nt_strrev(s5);
	(strcmp(s5, e5) == 0) ? puts("PASS") : puts ("FAIL");

	test__nt_keep_chars();
	test__nt_starts_with();

} // main()


void test__nt_keep_chars(void) {
	puts("nt_keep_chars()");
	char s6[] = "Keep only the vowels";
	char e6[] = "eeoeoe";
	nt_keep_chars(s6, "aeiou");
	(strcmp(s6, e6) == 0) ? puts("PASS") : puts ("FAIL");

	char s7[] = "Content Size: 1024";
	char e7[] = "1024";
	nt_keep_chars(s7, "0123456789");
	(strcmp(s7, e7) == 0) ? puts("PASS") : puts ("FAIL");
	
	char s8[] = "2017: A String Odyssey";
	char e8[] = "2017";
	nt_keep_chars(s8, "9876543210");
	(strcmp(s8, e8) == 0) ? puts("PASS") : puts ("FAIL");
}


void test__nt_starts_with(void) {
	puts("nt_starts_with()");
	char s0[] = "This starts with This";
	bool e0 = true;
	bool r0 = nt_starts_with(s0, "This");
	(e0 == r0) ? puts("PASS") : puts("FAIL");

	char s1[] = "But This not starts with This";
	bool e1 = false;
	bool r1 = nt_starts_with(s1, "This");
	(e1 == r1) ? puts("PASS") : puts("FAIL");
}

