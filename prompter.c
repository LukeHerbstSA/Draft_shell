#include "main.h"

char **prompt(void)
{
	char **args;
	char *buffer;
	char *buffer2;
	char *line_buff;
	char *token;
	size_t buffsize = 0;
	int gen;
	int len;

	gen = 0;
	buffer = malloc(150);
	line_buff = malloc(100);
	printf("$ ");
	while (1) /* Need to test for EOF  instead of '\0' - So that I can break with Ctrl+D */
	{
		gen = getline(&line_buff, &buffsize, stdin);
		if (gen == -1)
			return (NULL)
		strcat(buffer, linebuff);
		if (line[-1] != '\n') /* breaks if theres no newline*/
			break;
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
