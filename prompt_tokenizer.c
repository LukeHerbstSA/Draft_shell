#include "main.h"

/**
	* tokenizer - char **ptr func
	* Description: tokenizes passed buffer into var args
	* @buffer: passed text from user input
	* Return: pointer to array of char pointers (or NULL)
	*/
char **tokenizer(char *buffer)
{
	char *buffer2;
	char *token;
	char **args;
	int gen;

	token = malloc(100);
	buffer2 = malloc(strlen(buffer) + 1);
	if (buffer2 == NULL)
		return (NULL);
	strcpy(buffer2, buffer);
	printf("buffer: %s\nbuffer2: %s\n", buffer, buffer2);
	token = strtok(buffer, "\n ");
	for (gen = 0; token != NULL; gen++)
	{
		token = strtok(NULL, "\n ");
	}
	args = malloc(gen * sizeof(char *) + 1);
	if (args == NULL)
		return (NULL);
	token = strtok(buffer2, "\n ");
	for (gen = 0; token != NULL; gen++)
	{
		args[gen] = malloc(strlen(token) + 1);
		strcpy(args[gen], token);
		token = strtok(NULL, "\n ");
	}
	args[gen] = NULL;
	free(token);
	free(buffer);
	free(buffer2);
	return (args);
}
