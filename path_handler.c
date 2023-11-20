#include "main.h"

struct dir_node
{
	char *dir;
	struct path *next;
};

char *path_builder()
{
	struct path *head;
	char *buffer = getenv("PATH");
	char *dir;
	char *tmp;

	tmp = malloc(sizeof(struct dir_node));
	head = tmp;
	dir = strtok(buffer, ":");
	if (buffer == NULL || tmp == NULL || dir == NULL)
		return NULL;
	while (dir != NULL)
	{
		tmp->dir = dir;
		dir = strtok(NULL, ":");
		if (dir == NULL)
		{
			tmp->next = NULL;
			break;
		}
		tmp->next = malloc(sizeof(struct dir_node));
		tmp = tmp->next;
	}
	return head;
}
