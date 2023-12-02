#include "main.h"

void main(void)
{
	char **user_cmds;
	char *first_arg;
	struct path *path_head;
	struct path *tmp;
        size_t pid;
	int restart = 1;

	while (1)
	{
		user_cmds = prompter(); /* If prompter == NULL, this loop needs to start again  (new prompt)*/
		path_head = exe_finder(); /* same goes for exe finder, unless it return a null pointer, then return bad name command */
		first_arg = user_cmds[0]; /* if there is no slashes in the file name  passed  (user typed ls instead of /bin/ls) do the directory search but if not, just execve */
		for (i = 0; first_arg[i] != '\0'; i++)
		{
			if (first_arg[i] == '/')
				break;
		}
		if (first_arg[i] != '\0')
		{
			pid = fork();
			if (pid == 0)
			{
				execve(first_arg, user_cmds; NULL);
				printf("Passed file does not exist");
				restart = 0;
			}
			wait(NULL);
		}
		if (restart == 1)
		{
			tmp = path_head;
			pid = fork();
			if (pid == 0)
			{
				while (tmp != NULL)
				{
					strcopy(user_cmds[0], tmp->dir);
					strcat(user_cmds[0], first_arg);
					execve(user_cmds[0], user_cmds, NULL);
					tmp = tmp->next;
				}
				if (tmp == NULL)
					printf("Something went wrong with the passed args\n");
			}
			wait(NULL);
			free(buffer);
			free(buffer2);
		}
}
