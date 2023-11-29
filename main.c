#include "main.h"

void main(void)
{
	char **user_cmds;
	char *first_arg;
	struct path *directories;
	struct path *tmp;
        size_t pid;

	while (1)
	{
		user_cmds = prompter();
		directories = exe_finder();
		first_arg = user_cmds[0];
		tmp = directories;
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
