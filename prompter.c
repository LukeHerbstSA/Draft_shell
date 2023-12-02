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

	gen = 0;
	len = 0;
	buffer = malloc(100);
	line_buff = malloc(100);
	printf("$ ");
	while (1)
	{
		gen = getline(&line_buff, &buffsize, stdin);
		if (gen == -1)
		{
			printf("Getline failed\n");
			return;
		}
		len += gen;
		if (linebuff[-1] != '\n')
		{
			len++;
			break;
		}
	}
	printf("After getline\n");
	buffer2 = malloc(len);
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
