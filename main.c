#include "main.h"

/**
	* main - int function
	* Description: loop that only breaks on error, to return int code to main
	*/
void main(void)
{
	char **user_cmds;
	char *buffer;
	char *first_arg;
	struct path *path_head;
	int gen;
	int exit_code;

	while (1)
	{
		while (1) /* Error codes may need a specific way to deal with them */
		{
			buffer = prompter();
			if (buffer == NULL)
				exit_code = 1;
			user_cmds = tokenizer(buffer);
			if (user_cmds == NULL)
			{
				printf("Something went wrong with the command you gave\n");
				exit_code = 2;
				break;
			}
			path_head = exe_finder();
			if (path_head == NULL)
			{
				printf("Something went wrong when building your PATH\n");
				exit_code = 3;
				break;
			}
			first_arg = user_cmds[0];
			gen = finder(path_head, user_cmds, first_arg);
			if (gen == -1)
			{
				printf("Something went wrong finding your file\n");
				exit_code = 4;
				break;
			}
		}
	}
}
