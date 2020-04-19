#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge
 */
void menger(int level)
{
	int i, j, dimension, d;

	if (level < 0)
		return;

	for (i = 0, dimension = 1; i < level; i++)
		dimension *= 3;
	for (i = 0; i < dimension; i++)
	{
		for (j = 0; j < dimension; j++)
		{
			for (d = dimension / 3; d; d /= 3)
			{
				if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
					break;
			}
			printf(d ? " " : "#");
		}
		printf("\n");
	}
}
