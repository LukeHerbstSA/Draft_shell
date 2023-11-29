#include "main.h"

char **prompt(void)
{
	char **args;
	char *buffer;
	char *buffer2;
	char *token;
	size_t buffsize = 0;
	int gen;

	buffer = malloc(100);

	printf("$ ");
	gen = getline(&buffer, &buffsize, stdin);
	if (gen == -1)
	{
		printf("Getline failed\n");
		return;
	}
	printf("After getline\n");
	buffer2 = malloc(gen);
	strcpy(buffer2, buffer);
	token = strtok(buffer, "\n ");
	for (gen = 0; token != NULL; gen++)
	{
		token = strtok(NULL, "\n ");
	}
	args = malloc(gen * sizeof(char *) + 1);
	token = strtok(buffer2, "\n ");
	for (gen = 0; token != NULL; gen++)
	{
		args[gen] = malloc(strlen(token) + 1);
		strcpy(args[gen], token);
		token = strtok(NULL, "\n ");
	}
	args[gen] = NULL;
	return (args);
}
