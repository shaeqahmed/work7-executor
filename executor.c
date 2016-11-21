#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

	char* command = (char *) calloc(1, 30);
	printf("What do you want to do? ");
	fgets(command, 25, stdin);

	int i = 0;
	for(; i < strlen(command); i++)
	{
		if(command[i] == '\n')
		{
			command[i] = 0;
			break;
		}
	}

	printf("\n");

	char* args[10];
	i = 0;
	char* originalCommand = command;
	int len = strlen(command);
	while(i < 10 && command - originalCommand <= strlen)
	{
		args[i] = strsep(&command, " ");
		i++;
	}

	char* actualArgs[i + 1];
	int j = 0;
	for(; j < i; j++)
	{
		actualArgs[j] = args[j];
		//printf("%s\n", actualArgs[j]);
	}
	actualArgs[i] = NULL;

	execvp(actualArgs[0], actualArgs);


	return 0;

}