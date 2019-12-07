#ifndef READ_H
# define READ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/fillit.h"

t_tetrem    *create_tetrems(int fd);
t_tetrem    *create_tetrem(char c, int *coords);
int         apply_tetrem(char c,int *coords, t_tetrem *head);
int         *get_coords_array(char *tetrem);
int         get_min_x(char *tetrem);
int         get_min_y(char *tetrem);
void        *free_list(t_tetrem *head);

#endif