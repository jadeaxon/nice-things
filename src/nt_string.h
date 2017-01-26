#pragma once

// Swaps the values in the two given variables.
// WARNING: Fails when a and b refer to same memory location.
#define NT_XOR_SWAP(a,b) a ^= b; b ^= a; a ^= b; 


char* nt_chop(char* s);
char* nt_chomp(char* s);
char* nt_strrev(char* s);
char* nt_keep_chars(char* s, char* keepers);

