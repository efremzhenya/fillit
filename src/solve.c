#include "solve.h"
#include "get_map.h"

int     solver(t_map *map, t_tetrem *tetrem)
{
    t_tetrem *head;
    t_tetrem *back;
    t_point start;
    int i;

    start.x = 0;
    start.y = 0;
    head = tetrem;
    back = tetrem;
    while (head != NULL)
    {
        if ((start = find_free_pos(start, map, head->tetrem)).x != -1)
        {
            paste_tetrem(map, head, start);
            head = head->next;
            start.x = 0;
            start.y = 0;
        }
        else
        {
            if (head->c == 'A')
            {
                //free and update map++
            }
            else
            {
                //start = del_tetrem_and_get_backpos(head->c, map);
                if ((start = del_tetrem_and_get_newpos(--(head->c), map)).x != -1)
                {
                    while (back->c != head->c)
                        back = back->next;
                    head = back;
                    back = tetrem;
                }
            }
        }
    }
    i = 0;
    while (map->size > i)
        ft_putstr(map->map[i++]);
    return (1);
}

t_point     find_free_point(t_point start, t_map *map)
{
    while (map->size > start.y)
    {
        if (map->map[start.y][start.x] == '.')
            return (start);
        if (map->map[start.y][start.x] == '\n')
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

int     get_width_on_first(int *tetrem)
{
    int min;
    int max;

    max = (tetrem[0] >= tetrem[2]) ? tetrem[0] : tetrem[2];
    max = (max >= tetrem[4]) ? max : tetrem[4];
    max = (max >= tetrem[6]) ? max : tetrem[6];
    return(max - tetrem[0] + 1);
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

int     get_height_on_first(int *tetrem)
{
    int min;
    int max;

    max = (tetrem[1] >= tetrem[3]) ? tetrem[1] : tetrem[3];
    max = (max >= tetrem[5]) ? max : tetrem[5];
    max = (max >= tetrem[7]) ? max : tetrem[7];
    return(max - tetrem[1] + 1);
}

t_point     find_free_pos(t_point start, t_map *map, int *tetrem)
{
    int w;
    int h;
    t_point buf;
    int i;
    int y;
    int x;

    w = get_width_on_first(tetrem);
    h = get_height_on_first(tetrem);
    while ((start = find_free_point(start, map)).x != -1)
    {
        if (map->size >= start.x + w && map->size >= start.y + h)
        {
            i = 2;
            while (i < 8)
            {
                x = start.x + (tetrem[i] - tetrem[0]);
                i++;
                y = start.y + (tetrem[i] - tetrem[1]);
                i++;
                if (map->map[y][x] != '.')
                    i = 9;
            }
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

    map->map[start.y][start.x] = tetrem->c;
    i = 2;
    while (i < 8)
    {
            step.x = tetrem->tetrem[i++] - tetrem->tetrem[0] + start.x;
            step.y = tetrem->tetrem[i++] - tetrem->tetrem[1] + start.y;

        map->map[step.y][step.x] = tetrem->c;
    }
    i = 0;
    while (map->size > i)
        ft_putstr(map->map[i++]);
}

t_point    del_tetrem_and_get_newpos(char c, t_map *map)
{
    int y;
    t_point back_start;
    int flag;
    int x;

    flag = 0;
    y = 0;
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
                    back_start.y = y;
                    back_start.x = x;
                    flag = 1;
                }
            }
            x++;
        }
        y++;
    }
    if (back_start.x++ >= map->size)
    {
        if (back_start.y++ >= map->size)
            back_start.x = -1;
        else
            back_start.x = 0;
    }
    print_map(map);
    return back_start;
}

t_point    del_tetrem_and_get_backpos(char c, t_map *map)
{
    int y;
    t_point back_start;
    char back_c;
    int flag;
    int x;

    flag = 0;
    y = 0;
    back_c = --c - 1;
    while (map->size > y)
    {
        x = 0;
        while (map->map[y][x] != '\n')
        {
            if (map->map[y][x] == c)
                map->map[y][x] = '.';
            else if (flag == 0 && map->map[y][x] == back_c)
            {
                back_start.y = y;
                back_start.x = x;
                flag = 1;
            }
            x++;
        }
        y++;
    }
    print_map(map);
    return back_start;
}
void    print_map(t_map *map)
{
    int i;

    i = 0;
    while (map->size > i)
        ft_putstr(map->map[i++]);
}