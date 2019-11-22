#include "read.h"
#include "../includes/fillit.h"
#include <stdio.h>

t_tetrem    *create_tetrems(int fd)
{
    char        c;
    char        *buf;
    int         *coords;
    t_tetrem    *t_list;
    
    c = 'A';
    buf = ft_strnew(20);
    t_list = NULL;
    while (read(fd, buf, 20) == 20)
    {
        coords = get_coords_array(buf);
        if (!t_list)
            t_list = create_tetrem(c++, coords);
        else if (!apply_tetrem(c++, coords, t_list))
        {
            free(coords);
            //TODO: fresh t_list!
            return (NULL);
        }
        read(fd, buf, 1);
        free(coords);
    }
    close(fd);
    print_coords(t_list);
    return t_list;
}

/*Testing func, Delete*/
void    print_coords(t_tetrem *t_list)
{
    int *p;

    p = NULL;
    while (t_list != NULL)
    {
        printf("--------\n");
        p = t_list->tetrem;
        while (*p)
        {
            printf("%i\n", *p);
            p++;
        }
        p = NULL;
        t_list = t_list->next;
    }
}

int     apply_tetrem(char c,int *coords, t_tetrem *head)
{
    t_tetrem *t_buf;

    t_buf = head;
    while (t_buf->next != NULL)
        t_buf = t_buf->next;
    if (!(t_buf->next = create_tetrem(c, coords)))
        return (0);
    return (1);
}

t_tetrem     *create_tetrem(char c, int *coords)
{
    t_tetrem    *new_tetrem;

    if (!(new_tetrem = (t_tetrem *)malloc(sizeof(t_tetrem))))
        return NULL;
    new_tetrem->c = c;
    new_tetrem->tetrem = coords;
    new_tetrem->next = NULL;
    return (new_tetrem);
}

int     *get_coords_array(char *tetrem)
{
    int *coords;
    int *p;
    int i;
    int min_x;
    int min_y;

    i = 0;
    min_x = get_min_x(tetrem);
    min_y = get_min_y(tetrem);
    if (!(coords = (int *)malloc(sizeof(int) * 9)))
        return (NULL);
    p = coords;
    while (tetrem[i] != '\0')
    {
        if (tetrem[i] == '#')
        {
            *coords = i % 5 - min_x + 1;
            coords++;
            *coords = i / 5 - min_y + 1;
            coords++;
        }
        i++;
    }
    *coords = '\0';
    return p;
}

int     get_min_y(char *tetrem)
{
    int i;

    i = 0;
    while (tetrem[i] != '#')
        ++i;
    return (i / 5);
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