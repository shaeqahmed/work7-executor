#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

	char* command = (char *) calloc(1, 30);
	printf("What do you want to do? ");
	fgets(command, 25, stdin);
	printf("\n");

	char* args[10];
	int i = 0;
	char* originalCommand = command;
	int len = strlen(command);
	while(i < 10 && command - originalCommand <= strlen)
	{
		args[i] = strsep(&command, " ");
		//printf("args[i]: %s\n", args[i]);
		i++;
	}
	//seems fine

	char* actualArgs[i];
	int j = 0;
	for(; j < i; j++) actualArgs[j] = args[j];

	execvp(actualArgs[0], &actualArgs[1]);


	return 0;

}