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
	dir = strtok(buffer, ":");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		printf("After a dir has been printed\n");
		dir = strtok(NULL, ":");
	}
	printf("after all paths have been printed");
	free(buffer);
	free(dir);
	return (0);
}
