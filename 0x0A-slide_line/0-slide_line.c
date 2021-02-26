#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * toRight - Move Right
 * @line: Pointer
 * @size: Size
 */

void toRight(int *line, size_t size)
{
	size_t i;
	int aux;

	for (i = size - 1; i > 0; i--)
	{
		aux = i - 1;
		if (line[i] == line[aux])
		{
			line[i] += line[aux];
			line[aux] = 0;
		}
	}
}

/**
 * Zright - No 0 to right
 * @line: Pointer
 * @size: Size
 */
void Zright(int *line, size_t size)
{
	size_t mv;
	int fnd, zrs, change, tmp, rn;

	mv = size - 1;
	do {
	fnd = 0;
	zrs = 0;
	for (rn = mv; rn >= 0; rn--)
	{
		if (line[rn] == 0)
		{
			zrs += 1;
		}
		else if (line[rn] != 0)
		{
			fnd = 1;
			break;
		}
	}
	change = mv - zrs;
	if (change >= 0)
	{
		tmp = line[mv];
		line[mv] = line[change];
		line[change] = tmp;
	}
	mv--;
	} while (fnd);
}

/**
 * toLeft - Move left
 * @line: Pointer
 * @size: Size
 */
void toLeft(int *line, size_t size)
{
	size_t mv;
	int tmp;

	for (mv = 0; mv < (size - 1); mv++)
	{
		tmp = mv + 1;
		if (line[mv] == line[tmp])
		{
			line[mv] += line[tmp];
			line[tmp] = 0;
		}
	}
}

/**
 * Zleft - No zeroes to left
 * @line: Pointer
 * @size: Size
 */
void Zleft(int *line, size_t size)
{
	int fnd, zrs, change, tmp, cnt, rn, siz;

	siz = size;
	cnt = 0;
	do {
	fnd = 0;
	zrs = 0;
	for (rn = cnt; rn < siz; rn++)
	{
		if (line[rn] == 0)
			zrs += 1;

		else if (line[rn] != 0)
		{
			fnd = 1;
			break;
		}
	}
	change = cnt + zrs;
	if (change < siz)
	{
		tmp = line[cnt];
		line[cnt] = line[change];
		line[change] = tmp;
	}
	cnt++;
	} while (fnd);
}

/**
 * slide_line - Move numbers
 * @line: Pointer
 * @size: Length of numbers
 * @direction: Direction
 * Return: 1 on success 0 on failure
 *
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == 0)
	{
		Zleft(line, size);
		toLeft(line, size);
		Zleft(line, size);
	}
	else if (direction == 1)
	{
		Zright(line, size);
		toRight(line, size);
		Zright(line, size);
	}
	else
		return (0);

return (1);
}
