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

char *exe_finder(void);

#endif
