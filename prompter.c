#include "main.h"

/**
	* prompt - char ptr
	* Description: prompts the user to pass some input
	* Return: pointer to buffer containing input
	*/
char *prompt(void)
{
	char **args;
	char *buffer;
	char *buffer2;
	char *line_buff;
	char *token;
	size_t buffsize = 0;
	int gen = 0;
	int len = 0;

	buffer = malloc(1024);
	line_buff = malloc(100);
	printf("$ ");
	while (1)
	{
		gen = getline(&line_buff, &buffsize, stdin);
		if (gen == -1)
		{
			printf("Getline failed\n");
			return (NULL);
		}
		len += gen;
		if (linebuff[-1] != '\n')
		{
			len++;
			break;
		}
	}
	printf("After getline\n");
	return (buffer);
}
