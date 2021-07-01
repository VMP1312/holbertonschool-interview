#include "holberton.h"

/**
 * infi_multi - Infinite multiplication
 * @n1: n1
 * @len1: Len 1
 * @n2: n2
 * @len2: Len 2
 * Return: resutl (pointer)
 */

int *infi_multi(char *n1, int len1, char *n2, int len2)
{
	int cnt;
	int mv;
	int mul;
	int *res;

	res = malloc((len2 + len1) * sizeof(int));

	if (res == NULL)
	{
		printter("Error\n");
		exit(98);
	}

	for (cnt = 0; cnt < len1 + len2; cnt++)
		res[cnt] = 0;

	for (cnt = len2 - 1; cnt >= 0; cnt--)
	{
		for (mv = len1 - 1; mv >= 0; mv--)
		{
			mul = (n2[cnt] - '0') * (n1[mv] - '0');
			res[cnt + mv + 1] += mul % 10;
			res[cnt + mv] += mul / 10;

			if (res[cnt + mv + 1] >= 10)
			{
				res[cnt + mv] += res[cnt + mv + 1] / 10;
				res[cnt + mv + 1] %= 10;
			}
		}
	}
	return (res);
}

/**
 * num_cnt_len - gets lenght
 * @num: str
 * Return: int len
 */

int num_cnt_len(char *num)
{
	int i = 0;

	for (; num[i] != '\0'; i++)
	{
		if (num[i] < 48 || num[i] > 57)
			return (-1);
	}
	return (i);
}

/**
 * printter - printer
 * @str: str
 */

void printter(char *str)
{
	int mv;

	for (mv = 0; str[mv] != '\0'; mv++)
		_putchar(str[mv]);
}


/**
 * main - multiplies two positive numbers
 * @argc: Argc
 * @argv: Argv
 * Return: Value or code error
 */

int main(int argc, char **argv)
{
	int i, len1, len2, *res;

	if (argc != 3)
	{
		printter("Error\n");
		exit(98);
	}

	len1 = num_cnt_len(argv[1]);
	len2 = num_cnt_len(argv[2]);

	if (len1 == -1 || len2 == -1)
	{
		printter("Error\n");
		exit(98);
	}

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printter("0\n");
		return (0);
	}

	res = infi_multi(argv[1], len1, argv[2], len2);

	if (!res[0])
		i = 1;

	else
		i = 0;

	for (; i < len1 + len2; i++)
		_putchar(res[i] + '0');

	_putchar('\n');
	free(res);

	return (0);
}
