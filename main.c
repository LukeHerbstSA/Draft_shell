#include "main.h"

/**
	* main - int function
	* Description: loop that only breaks on error, to return int code to main
	* Return: always 0
	*/
int main(void)
{
	char **user_cmds;
	char *buffer;
	char *first_arg;
	struct path *path_head;
	int exit_code = 0;

	while (1)
	{
		while (1) /* Error codes may need a specific way to deal with them */
		{
			buffer = prompt();
			if (buffer == NULL)
				return (0);
			printf("After prompted returned buffer\n");
			user_cmds = tokenizer(buffer);
			if (user_cmds == NULL)
			{
				printf("Something went wrong with the command you gave\n");
				exit_code = 1;
				break;
			}
			path_head = exe_finder();
			printf("After user_cmds has been filled and exe has been built\n");
			if (path_head == NULL)
			{
				printf("Something went wrong when building your PATH\n");
				exit_code = 2;
				break;
			}
			first_arg = user_cmds[0];
			if (finder(path_head, user_cmds, first_arg) == -1)
			{
				printf("Something went wrong finding your file\n");
				exit_code = 3;
				break;
			}
		}
	}
	return (0);
}
