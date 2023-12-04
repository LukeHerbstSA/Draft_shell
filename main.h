#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct path
{
	char *dir;
	struct path *next;
};

char **tokenizer(char *buffer);
char **prompt(void);
struct path *exe_finder(void);
int finder(struct path *path_head, char **user_cmds, char *first_arg);

#endif
