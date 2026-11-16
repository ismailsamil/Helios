#include <stdio.h>
#include <string.h>

#include "db.h"

int db_set(int key, const char *value)
{
    FILE *file = fopen("database.txt", "a");

    if (file == NULL) {
        printf("Error occurred while opening database file\n");
        return 1;
    }

    fprintf(file, "%d\t%s\n", key, value);

    fclose(file);

    return 0;
}


KeyValue *db_get(int wanted_key)
{
    char line[2048];
    int key;
    char value[2000];

    static KeyValue result;

    int found = 0;

    FILE *file = fopen("database.txt", "r");

    if (file == NULL) {
        return NULL;
    }

    while (fgets(line, sizeof(line), file) != NULL) {

        if (sscanf(line, "%d\t%1999[^\n]", &key, value) == 2) {

            if (key == wanted_key) {

                result.key = key;

                strcpy(result.value, value);

                found = 1;
            }
        }
    }

    fclose(file);

    if (found == 0) {
        return NULL;
    }

    return &result;
}

