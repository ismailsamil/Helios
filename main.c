#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db.h"


int main(int argc, char *argv[])
{
    if (argc < 2) {

        printf("Usage:\n");
        printf("  ./mydb set <key> <value>\n");
        printf("  ./mydb get <key>\n");

        return 1;
    }

    char *command = argv[1];


    if (strcmp(command, "set") == 0) {

        if (argc != 4) {

            printf("Usage: ./mydb set <key> <value>\n");

            return 1;
        }

        int key = atoi(argv[2]);

        char *value = argv[3];


        int result = db_set(key, value);


        if (result == 0) {

            printf("OK\n");

        } else {

            printf("Failed to save value\n");
        }
    }


    else if (strcmp(command, "get") == 0) {

        if (argc != 3) {

            printf("Usage: ./mydb get <key>\n");

            return 1;
        }

        int key = atoi(argv[2]);


        KeyValue *result = db_get(key);


        if (result != NULL) {

            printf("%d\t%s\n",
                   result->key,
                   result->value);

        } else {

            printf("Key not found\n");
        }
    }


    else {

        printf("Unknown command: %s\n", command);

        return 1;
    }


    return 0;
}
