#pragma once

// Swaps the values in the two given variables.
// WARNING: Fails when a and b refer to same memory location.
#define NT_XOR_SWAP(a,b) a ^= b; b ^= a; a ^= b; 


/*
do\
{\
	a ^= b;\
	b ^= a;\
	a ^= b;\
} while (0)

*/




char* nt_chop(char* s);
char* nt_chomp(char* s);
char* nt_strrev(char* s);


