#ifndef SOLVE_H
# define SOLVE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/fillit.h"

int     solver(t_map *map, t_tetrem *tetrem);
t_point     find_free_point(t_point start, t_map *map);
int     get_width(int *tetrem);
int     get_height(int *tetrem);
t_point     find_free_pos(t_point start, t_map *map, int *tetrem);
void    paste_tetrem(t_map *map, t_tetrem *tetrem, t_point start);
void    print_map(t_map *map);

#endif