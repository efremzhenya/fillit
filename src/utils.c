# include "../includes/fillit.h"

t_point     sizes(int *tetrem)
{
    t_point size;
    int width;
    int height;

    width = (tetrem[0] >= tetrem[2]) ? tetrem[0] : tetrem[2];
    width = (width >= tetrem[4]) ? width : tetrem[4];
    width = (width >= tetrem[6]) ? width : tetrem[6];
    size.x = width - tetrem[0] + 1;
    height = (tetrem[1] >= tetrem[3]) ? tetrem[1] : tetrem[3];
    height = (height >= tetrem[5]) ? height : tetrem[5];
    height = (height >= tetrem[7]) ? height : tetrem[7];
    size.y = height - tetrem[1] + 1;
    return(size);
}

t_point get_position(int y, int x, t_map *map)
{
    t_point point;

    point.x = x;
    point.y = y;

    if (point.x++ >= map->size)
    {
        if (point.y++ >= map->size)
            point.x = -1;
        else
            point.x = 0;
    }
    return point;
}

int     get_min_x(char *tetrem)
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