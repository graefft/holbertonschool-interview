#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int add_sandpiles(int grid1[3][3], int grid2[3][3]);
void topple_sandpile(int grid1[3][3], int grid2[3][3]);
void print_sand(int grid[3][3]);

#endif
