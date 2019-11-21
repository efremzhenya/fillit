#ifndef READ_H
# define READ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/fillit.h"

t_tetrem    *save_tetrem(char c, char *tetrem);
int         get_min_x(char *tetrem);
int         get_min_y(char *tetrem);
int         *create_one(char *tetrem);
t_tetrem    *create_tetrems(char *file);

#endif