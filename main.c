#include <stdio.h>
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

    /*
        SET command

        Example:
        ./mydb set name '{"value":"Ismail"}'

        argv[0] = "./mydb"
        argv[1] = "set"
        argv[2] = "name"
        argv[3] = "{\"value\":\"Ismail\"}"
    */
    if (strcmp(command, "set") == 0) {

        if (argc != 4) {
            printf("Usage: ./mydb set <key> <value>\n");
            return 1;
        }

        char *key = argv[2];
        char *value = argv[3];

        int result = db_set(key, value);

        if (result == 0) {
            printf("OK\n");
        } else {
            printf("Failed to save value\n");
        }
    }

    /*
        GET command

        Example:
        ./mydb get name

        argv[0] = "./mydb"
        argv[1] = "get"
        argv[2] = "name"
    */
    else if (strcmp(command, "get") == 0) {

        if (argc != 3) {
            printf("Usage: ./mydb get <key>\n");
            return 1;
        }

        char *key = argv[2];

        char *value = db_get(key);

        if (value != NULL) {
            printf("%s\n", value);
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
