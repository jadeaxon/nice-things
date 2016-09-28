// Cryptographic functions for the Nice Things C library.

#include "nt_crypt.h"


// Encrypts/decrypts string by xor'ing each char with given cypher char.
// Mutates the given string.
char* nt_xor_crypt(char* s, char cypher) {
	while (*s != '\0') {
		*s ^= cypher;
		s++;
	}
} // nt_xor_crypt()


