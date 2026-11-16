#ifndef DB_H
#define DB_H

int db_set(const char *key, const char *value);

char *db_get(const char *key);
#endif

