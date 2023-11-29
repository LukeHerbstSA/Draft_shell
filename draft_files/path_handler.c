#include "main.h"

struct path;
/**
	* exe_finder - char *ptr func
	* Description: builds a singly linked list from path variable
	* Return: struct path *head so main func can access the list
	*/
struct path *exe_finder(void)
{
	struct path *head;
	char *buffer = getenv("PATH");
	char *dir;
	struct path *tmp;

	tmp = malloc(sizeof(struct path));
	head = tmp;
	dir = strtok(buffer, ":");
	if (buffer == NULL || tmp == NULL || dir == NULL)
		return (NULL);
	while (dir != NULL)
	{
		tmp->dir = dir;
		dir = strtok(NULL, ":");
		if (dir == NULL)
		{
			tmp->next = NULL;
			break;
		}
		tmp->next = malloc(sizeof(struct path));
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->dir);
		tmp = tmp->next;
	}
	return (head);
}
