#include "read.h"
#include "../includes/fillit.h"

t_tetrem    *create_tetrems(int fd, char c)
{
    char        *buf;
    int         *coords;
    t_tetrem    *t_list;
    
    buf = ft_strnew(20);
    t_list = NULL;
    while (read(fd, buf, 20) == 20)
    {
        coords = get_coords_array(buf);
        if (!t_list)
            t_list = create_tetrem(c++, coords);
        else if (!(apply_tetrem(c++, coords, t_list)))
        {
            free(buf);
            free(coords);
            free_list(t_list);
            return (NULL);
        }
        read(fd, buf, 1);
        free(coords);
    }
    close(fd);
    free(buf);
    return t_list;
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
    if (!(new_tetrem->tetrem = (int *)malloc(sizeof(int) * 9)))
	{
        free(new_tetrem);
        return (NULL);
    }
    ft_memcpy(new_tetrem->tetrem, coords, (sizeof(int) * 9));
    new_tetrem->c = c;
    new_tetrem->next = NULL;
    return (new_tetrem);
}

int     *get_coords_array(char *tetrem)
{
    int *coords;
    int i;
    int min_x;
    int min_y;

    i = 0;
    while (tetrem[i] != '#')
        ++i;
    min_y = (i / 5);
    min_x = get_min_x(tetrem);
    if (!(coords = (int *)malloc(sizeof(int) * 9)))
        return (NULL);
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
    return (coords - 8);
}

void    free_list(t_tetrem *head)
{
    while(head != NULL)
    {
        free(head->tetrem);
        head->tetrem = NULL;
        head = head->next;
    }
    free(head);
    head = NULL;
}