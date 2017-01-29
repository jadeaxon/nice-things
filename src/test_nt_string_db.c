#include "nt_string_db.h"

#include <stdio.h>
#include <string.h>


// Tests the functions declared in nt_string_db.h.
int main(void) {
	puts("nt_create_string_db()");
	StringDatabase* sdb = nt_create_string_db();
	puts("PASS");	
	
	// char v[sdb->MAX_STRING_SIZE];
	puts("nt_string_db_open()");
	sdb->open(sdb, "test.db");
	puts("PASS");

	puts("nt_string_db_put()");
	char* v = NULL;
	char k[80] = "exit()";
	char e[1024] = "stdlib";
	sdb->put(sdb, k, e);
	puts("PASS");
	sdb->put(sdb, "mykey", "myvalue");
	puts("PASS");

	puts("nt_string_db_get()");
	v = sdb->get(sdb, k);
	(strcmp(v, e) == 0) ? puts("PASS") : puts("FAIL");

	v = sdb->get(sdb, "mykey");
	(strcmp(v, "myvalue") == 0) ? puts("PASS") : puts("FAIL");

	return 0;
} // main()


