#include "menger.h"
/**
 *menger - display 2D
 *@level: integer
 *Return: true
*/

void menger(int level)
{
	int x, w, size, height, width;
	char ch;

	x = 0;
	y = 0;
	if (level < 0)
	{
		return;
	}
	else if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (level > 0)
	{
	size = pow(3, level);
	}

	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			width = y;
			height = x;
			ch = '#';
			while (height > 0)
			{
				if (height % 3 == 1 && width % 3 == 1)
					ch = ' ';
				height = height / 3;
				width = width / 3;
			}
			printf("%c", ch);
			y++;
		}
		printf("\n");
		x++;
	}
}
