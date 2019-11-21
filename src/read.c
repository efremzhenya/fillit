#include "read.h"
#include "../includes/fillit.h"

t_tetrem    *create_tetrems(char *file)
{
    char        c;
    int         fd;
    char        *buf;
    t_tetrem    *tetrems_list;
    t_tetrem    *p_list;
    
    c = 'A';
    buf = ft_strnew(20);
    if ((fd = open(file, O_RDONLY)) < 0)
		return(NULL);
	else
	{
		if (read(fd, buf, 20))
		{
            tetrems_list->c = c++;
            tetrems_list->tetrem = create_one(buf);
            tetrems_list->next = NULL;
            p_list = tetrems_list;
            read(fd, buf, 1);
		}
        while (read(fd, buf, 20))
		{
            tetrems_list->next = save_tetrem(c++, buf);
            read(fd, buf, 1);
            //TODO: fresh!
		}
        return p_list;
	}
    return(NULL);

}
t_tetrem     *save_tetrem(char c, char *tetrem)
{
    int         *new_tetrem;
    t_tetrem    *tetrems_list;

    tetrems_list->c = c;
    tetrems_list->tetrem = create_one(tetrem);
    tetrems_list->next = NULL;
    return (&tetrems_list);
}

int     *create_one(char *tetrem)
{
    int *coords;
    int *p;
    int i;
    int min_x;
    int min_y;

    i = 0;
    min_x = get_min_x(tetrem);
    min_y = get_min_y(tetrem);
    if (!(coords = (int *)malloc(sizeof(int) * 8)))
        return (NULL);
    p = coords;
    while (tetrem[i] != '\0')
    {
        if (tetrem[i] == '#')
        {
            *coords = i % 5 - min_x;
            printf ("x = %i \n", *coords);
            coords++;
            *coords = i / 5 - min_y;
            printf("y = %i \n", *coords);
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