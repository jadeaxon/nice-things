#include "nt_string_db.h"

#include <stdio.h>
#include <string.h>


// Tests the functions declared in nt_string_db.h.
int main(void) {
	puts("nt_create_string_db()");
	puts("nt_string_db_open()");
	puts("nt_string_db_put()");
	puts("nt_string_db_get()");
	StringDatabase* sdb = nt_create_string_db();
	// char v[sdb->MAX_STRING_SIZE];
	char* v = NULL;
	sdb->open(sdb, "test.db");
	char k[80] = "exit()";
	char e[1024] = "stdlib";
	sdb->put(sdb, k, e);
	v = sdb->get(sdb, k);
	(strcmp(v, e) == 0) ? puts("PASS") : puts("FAIL");

} // main()


