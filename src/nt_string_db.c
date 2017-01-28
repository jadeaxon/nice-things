#include "nt_string_db.h"

// C
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <string.h> // memset()

// Berkeley DB
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
StringDatabase* nt_create_string_db(void) {
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
	sdb->MAX_KEY_SIZE = 80;
	sdb->MAX_STRING_SIZE = 1024;

	// Register instance methods.
	sdb->open = nt_string_db_open;
	sdb->put = nt_string_db_put;
	sdb->get = nt_string_db_get;

} // nt_create_string_db(char*)


//=============================================================================
// Instance Methods

// Opens a StringDatabase to file at given path.  Creates database file if DNE. 
void nt_string_db_open(StringDatabase* this, char* path) {
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
	
} // nt_string_db_open(...)


// Puts a string into the database.
// PRE: Key and string value are not too large.
// PRE: String database is open.
void nt_string_db_put(StringDatabase* this, char* key, char* value) {
	// BDB uses a DBT type to rep both.  It is a void* and a length.
    // So it is a serialize blob of some amount of any kind of data.
    DBT db_key, db_value;

	if (strlen(key) > this->MAX_KEY_SIZE) {
		fprintf(stderr, "ERROR: put: Key is too large:\n%s\n", key);
		exit(1);
	}

	if (strlen(value) > this->MAX_STRING_SIZE) {
		fprintf(stderr, "ERROR: put: String is too large.\n");
		exit(1);
	}

    /* Zero out the DBTs before using them. */
    memset(&db_key, 0, sizeof(DBT));
    memset(&db_value, 0, sizeof(DBT));
    db_key.data = key;
    db_key.size = this->MAX_KEY_SIZE;
    db_value.data = value;
    db_value.size = this->MAX_STRING_SIZE;

    // Okay, so we have a key and value DBT.  How do we put that in the database?
    // 2nd arg is transaction this access is part of.  We're not using transactions.
    // Last argument is flags affecting execution of put().
    int error = this->dbp->put(this->dbp, NULL, &db_key, &db_value, 0);
    dbe(error, "Failed to put record into database");
} // nt_string_db_put(...)


// Gets a string from the database given its key.
// PRE: The key is not too large.
char* nt_string_db_get(StringDatabase* this, char* key) {
	if (strlen(key) > this->MAX_KEY_SIZE) {
		fprintf(stderr, "ERROR: get: Key is too large:\n%s\n", key);
		exit(1);
	}

	/* Zero out the DBTs before using them. */
    DBT db_key, db_value;
    memset(&db_key, 0, sizeof(DBT));
    memset(&db_value, 0, sizeof(DBT));
    db_key.data = key;
    db_key.size = this->MAX_KEY_SIZE;
    db_value.ulen = this->MAX_STRING_SIZE;
    db_value.flags = DB_DBT_USERMEM; // Use our own memory to ward off alignment problems.
    int error = this->dbp->get(this->dbp, NULL, &db_key, &db_value, 0);
    dbe(error, "Failed to get record from database");
} // nt_string_db_put();


