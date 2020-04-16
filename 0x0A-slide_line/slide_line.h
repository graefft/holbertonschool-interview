#ifndef __SLIDE_LINE__
#define __SLIDE_LINE__

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

#include <stdio.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);
#endif /* __SLIDE_LINE__ */
