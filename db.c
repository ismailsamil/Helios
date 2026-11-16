#include <stdio.h>
#include <string.h>

int db_set(const char *key,const char *value){
	FILE *file=fopen("database.txt","a");
	
	if(file==NULL){
	printf("Error occurred while creating a file");
		return 1;
	}

	fprintf(file, "%s\t%s\n", key, value);
	
	fclose(file);
	return 0;
}

char *db_get(const char *wanted_key){
	//defined latest value size
	static char latest_value[1024];
	char line[2048];
	char key[256];
	char value[1024];

	FILE *file=fopen("database.txt","r");
	
	// if file return program will exit
	if (file ==NULL){
		return NULL;
	}

	latest_value[0]='\0';
	while(fgets(line,sizeof(line),file)!=NULL){
		if(sscanf(line,"%255[^\t]\t%1023[^\n]", key, value) == 2) {
			if (strcmp(key, wanted_key) == 0) {
            		    strcpy(latest_value, value);
           		 }
		}

	}

	fclose(file);

 	if (latest_value[0] == '\0') {
		printf("issue occurs during extraction process");
        	return NULL;
    	}
	return latest_value;
}


