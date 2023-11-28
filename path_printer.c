#include "main.h"

/**
	* main - entry
	* Description: prints path
	* Return: always 0
	*/
int main(void)
{
	char *buffer;
	char *dir;

	buffer = malloc(1024);
	dir = malloc(100);
	printf("Before getenv");
	buffer = getenv("PATH");
	printf("%s\n", buffer);
	dir = strtok(buffer, ":") + 1;
	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":") + 1;
	}
	free(buffer);
	return (0);
}
