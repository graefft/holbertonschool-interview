#include "sandpiles.h"

/**
 * sandpiles_sum - sums two sandpiles and topples if any piles are over 3
 * @grid1: first grid of sandpiles
 * @grid2: second grid of sandpiles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int add_return = 0;

	add_return = add_sandpiles(grid1, grid2);
	while (add_return != 0)
	{
		topple_sandpile(grid1, grid2);
		add_return = add_sandpiles(grid1, grid2);
	}
}

/**
 * add_sandpiles - adds two sandpiles together
 * @grid1: first grid to add grid2 into
 * @grid2: grid to add to grid1
 * Return: 0 if stable or 1 if need to topple
 */
int add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int i, j, print_flag = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = (grid1[i][j] + grid2[i][j]);
			grid2[i][j] = 0;
			if (grid1[i][j] > 3)
				print_flag = 1;
		}
	}
	if (print_flag)
		return (1);
	else
		return (0);
}

/**
 * topple_sandpile - topples sandpile by spreading out to adjacent piles
 * @grid1: grid to topple
 * @grid2: grid to change new piles to
 */
void topple_sandpile(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	printf("=\n");
	print_sand(grid1);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
			}
		}
	}
}

/**
 * print_sand - prints grid at current state
 * @grid: grid to print
 */
void print_sand(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
