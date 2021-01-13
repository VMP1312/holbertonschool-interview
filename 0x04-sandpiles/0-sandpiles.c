#include "sandpiles.h"

/**
* printer - printer for the first grid
* @grid: grid 1
* Return: Void
*/

static void print_grid(int grid[3][3])
{
    int i;
    int j;

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

/**
 * sandpiles_sum - sum sandpiles
 * @grid1: grid 1
 * @grid2: grid 2
 * Return: Void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i = 0;
    int j = 0;
    int stl = 0;
    int cnt = 0;
    int check = 0;

    while (cnt == 0)
    {
        stl = 0;
        if (check != 0)
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    grid2[i][j] = grid1[i][j];
                    if (grid1[i][j] <= 3)
                        stl++;
                }
            }

            if (stl == 9)
            break;
            printf("=\n");
            print_grid(grid1);
        }

        stl = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (check != 0)
                {
                    if (grid2[i][j] > 3)
                    {
                        grid1[i][j] = grid1[i][j] - 4;
                        if (j > 0)
                            grid1[i][j - 1] = (grid1[i][j - 1]) + 1;
                        if (i > 0)
                            grid1[i - 1][j] = (grid1[i - 1][j]) + 1;
                        if (i < 2)
                            grid1[i + 1][j] = (grid1[i + 1][j]) + 1;
                        if (j < 2)
                            grid1[i][j + 1] = (grid1[i][j + 1]) + 1;
                    }
                    else
                        stl++;
                }
            else
                grid1[i][j] = grid1[i][j] + grid2[i][j];
            }
        }
    check = 1;
    }
}
