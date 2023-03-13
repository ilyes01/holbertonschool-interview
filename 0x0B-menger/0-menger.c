#include <stdio.h>
#include <math.h>

void draw_char(int x, int y, char c, int level);

/**
 * menger - Draws a 2D Menger Sponge of a given level
 *
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size = (int) pow(3, level);

	if (level < 0)
		return;

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			draw_char(col, row, '#', level);
		}
	}
}

/**
 * draw_char - Draws a character on a given position, based on the Menger level
 *
 * @x: The x position of the character
 * @y: The y position of the character
 * @c: The character to draw
 * @level: The level of the Menger Sponge being drawn
 */
void draw_char(int x, int y, char c, int level)
{
	while (level > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
		{
			c = ' ';
		}
		x /= 3;
		y /= 3;
		level--;
	}
	printf("%c", c);
}
