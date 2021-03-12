#include "menger.h"
/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level
 */

void menger(int level)
{
	int cnt, mv, aux, x, y;
	char printer;

	mv = pow(3, level);
	for (cnt = 0; cnt < mv; cnt++)
	{
		for (aux = 0; aux < mv;)
		{
			printer = '#';
			y = aux++;
			x = cnt;
			while (y > 0 || x > 0)
			{
				if (y % 3 == 1 && x % 3 == 1)
					printer = ' ';

				y = y / 3;
				x = x / 3;
			}
			printf("%c", printer);
		}
		printf("\n");
	}
}
