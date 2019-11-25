#include "solve.h"

int     solver(t_map *map, t_tetrem *tetrem)
{
    t_tetrem *head;
    t_point start;

    start.x = 0;
    start.y = 0;
    head = tetrem;
    while (head != NULL)
    {
        if ((start = find_free_pos(start, map, tetrem->tetrem)).x != -1)
            paste_tetrem(map, tetrem, start);
        else
            return (0); //free map and get new size+1!;
        head = head->next;
    }
    ft_putstr(map->map);
}

t_point     find_free_point(t_point start, t_map *map)
{
    while (map->size >= start.x && map->size >= start.y)
    {
        if (map->map[start.x][start.y] == '.')
            return (start);
        if (map->map[start.x][start.y] == '\n')
        {
            start.x = 0;
            start.y++;
        }
        start.x++;
    }
    start.x = -1;
    return (start);
}

int     get_width(int *tetrem)
{
    int min;
    int max;

    max = (tetrem[0] >= tetrem[2]) ? tetrem[0] : tetrem[2];
    max = (max >= tetrem[4]) ? max : tetrem[4];
    max = (max >= tetrem[6]) ? max : tetrem[6];
    min = (tetrem[0] <= tetrem[2]) ? tetrem[0] : tetrem[2];
    min = (min <= tetrem[4]) ? min : tetrem[4];
    min = (min <= tetrem[6]) ? min : tetrem[6];

    return(max - min + 1);
}

int     get_height(int *tetrem)
{
    int min;
    int max;

    max = (tetrem[1] >= tetrem[3]) ? tetrem[1] : tetrem[3];
    max = (max >= tetrem[5]) ? max : tetrem[5];
    max = (max >= tetrem[7]) ? max : tetrem[7];
    min = (tetrem[0] <= tetrem[3]) ? tetrem[1] : tetrem[3];
    min = (min <= tetrem[5]) ? min : tetrem[5];
    min = (min <= tetrem[7]) ? min : tetrem[7];
    return(max - min + 1);
}


t_point     find_free_pos(t_point start, t_map *map, int *tetrem)
{
    int w;
    int h;
    t_point buf;
    int i;

    w = get_width(tetrem);
    h = get_height(tetrem);
    while ((start = find_free_point(start, map)).x != -1)
    {
        if (map->size >= start.x + w && map->size >= start.y + h)
        {
            i = 2;
            while (tetrem[i++] - 1 == '.' && tetrem[i++] == '.' && i < 8);
            if (i == 8)
                return (start);
        }
        if (start.x++ + w > map->size)
        {
            start.x = 0;
            start.y++;
        }
    }
    start.x = -1;
    return(start);
}

void    paste_tetrem(t_map *map, t_tetrem *tetrem, t_point start)
{
    int i;
    t_point step;

    map->map[start.x][start.y] = tetrem->c;
    i = 2;
    while (i < 8)
    {
        step.x = tetrem->tetrem[i++] - 1 - start.x;
        step.y = tetrem->tetrem[i++] - 1 - start.y;
        start.x = start.x + step.x;
        start.y = start.y + step.y;
        map->map[start.x][start.y] = tetrem->c;
    }
}