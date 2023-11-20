#include "main.h"

int main(void)
{
	char **args;
	char *buffer;
	char *buffer2;
	char *token;
	size_t buffsize = 0;
	size_t pid;
	int gen;

	buffer = malloc(100);
	while (1)
	{
		printf("$ ");
		gen = getline(&buffer, &buffsize, stdin);
		if (gen == -1)
		{
			printf("Getline failed\n");
			return (-1);
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
		pid = fork();
		if (pid == 0)
			execve(args[0], args, NULL);
		wait(NULL);
		free(buffer);
		free(buffer2);
	}
}
