#pragma once

#include <db.h>

typedef struct string_db StringDatabase;
struct string_db {
	DB* dbp; // Berkeley DB pointer	
	void (*open)(StringDatabase*, char* path);
	void (*put)(StringDatabase*, char* key, char* value);
	char* (*get)(StringDatabase*, char* key);
};

StringDatabase* nt_create_string_db(char* path);
void nt_string_db_error(int error, char* msg);

void nt_string_database_open(StringDatabase* this, char* path);
void nt_string_database_put(StringDatabase* this, char* key, char* value);
char* nt_string_database_get(StringDatabase* this, char* key);


