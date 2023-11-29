#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct path *exe_finder(void);

struct path
{
	char *dir;
	struct path *next;
};

#endif
