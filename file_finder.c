#include "main.h"

/**
	* file_finder - int func
	* Description: Concatenates command onto PATH exec paths
	* @user_cmds: array of user args
	* @tmp: path to struct
	* Return: return 0
	*/
int file_finder(char **user_cmds, struct path *tmp)
{
	size_t pid;
	char *first_arg;

	first_arg = user_cmds[0];
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
		{
			printf("Command not found in PATH\n");
		}
	}
	wait(NULL);
	return (0);
}
