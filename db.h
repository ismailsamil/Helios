#ifndef DB_H
#define DB_H

typedef struct {
    int key;
    char value[2000];
} KeyValue;

int db_set(int key, const char *value);

KeyValue *db_get(int wanted_key);

#endif
