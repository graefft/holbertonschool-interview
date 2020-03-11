#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid_sum(int grid1[3][3], int grid2[3][3]);
int add_sandpiles(int grid1[3][3], int grid2[3][3]);
void topple_sandpile(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);

#endif
