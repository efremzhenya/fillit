#include "read.h"
#include "../includes/fillit.h"

t_tetrem     *save_tetrem(char *tetrem)
{
    char    sym;
    int     *new_tetrem;

    sym = 'A';
    new_tetrem = create_one(tetrem);
    return (NULL);
}

int     *create_one(char *tetrem)
{
    int     *tetremino;
    int i;
    int x_min;
    int y_min;

    i = 0;
    x_min = find_x(*tetrem);
    y_min = find_y(*tetrem);
    tetremino = (int *)malloc(sizeof(int) * 8);

}

int     find_x(char *tetrem)
{
    int i;

    i = 0;
    while (tetrem[i] != '#')
        ++i;
    return (i / 5);
}

int     find_y(char *tetrem)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tetrem[i] != '#')
    {
        i = i + 5;
        if (i > 19)
            i = ++j;
    }
    return (j);
}