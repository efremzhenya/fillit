#include "solve.h"
#include "get_map.h"
# include "../includes/fillit.h"

void     solver(t_map *map, t_tetrem *tetrem, t_tetrem *head,
 t_tetrem *back, t_point start)
{
    while (head != NULL)
    {
        if ((start = find_free_pos(start, map, head->tetrem, 0, 0)).x != -1)
        {
            start = paste_tetrem(map, head, start);
            head = head->next;
        }
        else
        {
            if (head->c == 'A')
                start = update_map(map);
            else
            {
                if ((start = del_tetrem(head->c - 1, map, 0, 0)).x != -1)
                {
                    while (back->c != head->c - 1)
                        back = back->next;
                    head = back;
                    back = tetrem;
                }
            }
        }
    }
}

t_point     find_free_point(t_point start, t_map *map)
{
    while (map->size > start.y)
    {
        if (map->map[start.y][start.x] == '.')
            return (start);
        else if (map->map[start.y][start.x] == '\n')
        {
            start.x = 0;
            start.y++;
        }
        else
            start.x++;
    }
    start.x = -1;
    return (start);
}

t_point     find_free_pos(t_point start, t_map *map, int *tetrem, int y, int x)
{
    int i;
    t_point size;

    size = sizes(tetrem);
    while ((start = find_free_point(start, map)).x != -1)
    {
        if (map->size >= start.x + size.x && map->size >= start.y + size.y)
        {
            i = 2;
            while (i < 8)
            {
                x = start.x + (tetrem[i++] - tetrem[0]);
                y = start.y + (tetrem[i++] - tetrem[1]);
                if (map->map[y][x] != '.')
                    i = 9;
            }
            if (i == 8)
                return (start);
        }
        if (start.x++ + size.x > map->size && ++start.y)
            start.x = 0;
    }
    return(start);
}

t_point    paste_tetrem(t_map *map, t_tetrem *tetrem, t_point start)
{
    int i;
    t_point step;

    map->map[start.y][start.x] = tetrem->c;
    i = 2;
    while (i < 8)
    {
        step.x = tetrem->tetrem[i++] - tetrem->tetrem[0] + start.x;
        step.y = tetrem->tetrem[i++] - tetrem->tetrem[1] + start.y;
        map->map[step.y][step.x] = tetrem->c;
    }
    step.x = 0;
    step.y = 0;
    return step;
}

t_point    del_tetrem(char c, t_map *map, int y, int x)
{
    t_point point;
    int flag;

    flag = 0;
    while (map->size > y)
    {
        x = 0;
        while (map->map[y][x] != '\n')
        {
            if (map->map[y][x] == c)
            {
                map->map[y][x] = '.';
                if (flag == 0)
                {
                    point = get_position(y, x, map);
                    flag = 1;
                }
            }
            x++;
        }
        y++;
    }
    return point;
}