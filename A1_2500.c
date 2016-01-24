#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "storeval.h"

void scanFile (char* path);
void scanTemp(char* path);
int main(int argc, char* argv[])
{
    scanFile(argv[1]);
		scanTemp(argv[2]);
	  return 0;
}
void scanFile (char* path)
{
    char* befSet;
	  char* aftSet;
	  FILE *dataFile;
 	  char string[256];
	  dataFile = fopen(path, "r"); //opens file
	  if(dataFile == NULL)
    {
        printf("Error opening file");
			  exit(0);
	  }
		//TODO: This breaks if there is any blank lines in the file.
	  while(fgets (string, 256, dataFile) != NULL)
    {
        befSet = strtok(string, "=");
		    aftSet = strtok(NULL, "\n");
				setValue(befSet, aftSet);
				/*if (setValue(befSet, aftSet) == 0)
				{
					printf("There was an error storing key/value: %s/%s\n",befSet, aftSet );
				}
		    printf("key: %s, value: %s\n", befSet, aftSet);
		}
		printf("Finished reading data file\n");*/
		}
	}
void scanTemp(char* path)
{
	char* befBrak;
	char* aftBrak;
	char parsedLine[256];
	char* name;
	char* value;
	FILE *tempFile;
	char string[256];
	tempFile = fopen(path, "r"); //opens file
	if(tempFile == NULL)
	{
			printf("Error opening file");
			exit(0);
	}
	printf("parsing template file\n");
	while(fgets (string, 256, tempFile) != NULL)
	{
			if(strchr(string, '{') != NULL)
			{
			  parsedLine[0] = '\0';
				befBrak = strtok(string, "{");
				//printf("parsed line = '%s', brefBrak = '%s'\n",parsedLine, befBrak );
				strcat(parsedLine, befBrak);
				name = strtok(NULL, "}");
				//printf("name = %s\n", name);
				//value = getValue(name);
				//printf("%s\n", befBrak);
				//printf("value = %s\n", value );
				strcat(parsedLine, value);
				aftBrak = strtok(NULL, "}");
				strcat(parsedLine, aftBrak);
			}
			else
			{
				strcpy(parsedLine, string);
			}
			printf("%s\n", parsedLine);
			/*printf("%s\n", value);
			printf("%s\n", string);
			printf("%s\n", befBrak );
			printf("%s\n", aftBrak);*/
		}
	}
}
