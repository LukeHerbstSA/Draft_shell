#include "main.h"

/**
	* prompt - char ptr
	* Description: prompts the user to pass some input
	* Return: pointer to buffer containing input
	*/
char *prompt(void)
{
	char *buffer;
	char *token;
	size_t buffsize = 0;
	int gen = 0;

	buffer = malloc(1024);
	token = malloc(100);
	printf("$ ");
	while (1)
	{
		if (getline(&token, &buffsize, stdin) == EOF)
		{
			printf("Getline was passed ctrl+d\n");
			return (NULL);
		}
		strcat(buffer, token);
		if (token[-1] != '\n')
			break;
	}
	printf("After getline\n");
	free (token);
	return (buffer);
}
