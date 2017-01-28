#pragma once

#include <db.h>

typedef struct string_db StringDatabase;
struct string_db {
	DB* dbp; // Berkeley DB pointer	
	int MAX_STRING_SIZE; // Max string size: 1024 default.	
	int MAX_KEY_SIZE; // Max key size: 80 default.
	void (*open)(StringDatabase*, char* path);
	void (*put)(StringDatabase*, char* key, char* value);
	char* (*get)(StringDatabase*, char* key);
};

StringDatabase* nt_create_string_db(char* path);
void nt_string_db_error(int error, char* msg);

void nt_string_db_open(StringDatabase* this, char* path);
void nt_string_db_put(StringDatabase* this, char* key, char* value);
char* nt_string_db_get(StringDatabase* this, char* key);


