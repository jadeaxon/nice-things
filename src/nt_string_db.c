#include "nt_string_db.h"

#include <stdio.h> // printf()
#include <stdlib.h> // exit()

#include <db.h> // sud!b nec

// dbe => nt_string_db_error in this file.
static void (*dbe)(int error, char* msg) = nt_string_db_error;


//=============================================================================
// Global Functions

// Prints a database error message.
void nt_string_db_error(int error, char* msg) {
	if (error) {
		fprintf(stderr, "ERROR: %s.\n", msg);
		exit(1);
	}
}


//=============================================================================
// Constructor

// Creates a string database.  Returns a pointer to it.
StringDatabase* nt_create_string_db(char* path) {
	DB* dbp = NULL; // Berkeley DB handle
    int error = 0; // Function error.

	// Create database.  2nd arg is NULL since not creating w/in a DB env.
    error = db_create(&dbp, NULL, 0);
    dbe(error, "Failed to create DB database instance");
	
	// Allocate StringDatabase instance on heap.
	StringDatabase* sdb = malloc(sizeof(StringDatabase));
	if (sdb == NULL) {
		fprintf(stderr, "ERROR: Failed to allocate memory for StringDatabase object.\n");
		exit(1);
	}
	sdb->dbp = dbp;

	// Register instance methods.
	sdb->open = nt_string_database_open;
	sdb->put = nt_string_database_put;
	sdb->get = nt_string_database_get;

} // nt_create_string_db(char*)


//=============================================================================
// Instance Methods

// Opens a StringDatabase to file at given path.  Creates database file if DNE. 
void nt_string_database_open(StringDatabase* this, char* path) {
	// Create database file on open if it does not already exist.
    u_int32_t flags = DB_CREATE; // Database open flags.
	int error = 0; // Function error.

    // Open the database.
    error = this->dbp->open(
		this->dbp, // DB pointer
        NULL, // Transaction pointer
        path, // Database file path
        NULL, // Logical database name
        DB_BTREE, // Database implementation (aka access method)
        flags, // Database creation flags
        0 // File mode (using default)
    );
    dbe(error, "Failed to open string database");
	
} // nt_string_database_open(...)


void nt_string_database_put(StringDatabase* sdb, char* key, char* value) {
	puts("Not implemented!");
}


char* nt_string_database_get(StringDatabase* sdb, char* key) {
	puts("Not implemented!");
}


