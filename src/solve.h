#ifndef SOLVE_H
# define SOLVE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/fillit.h"

void     solver(t_map *map, t_tetrem *tetrem, t_tetrem *head, t_tetrem *back, t_point start);
t_point     find_free_point(t_point start, t_map *map);
t_point     find_free_pos(t_point start, t_map *map, int *tetrem, int y, int x);
t_point    paste_tetrem(t_map *map, t_tetrem *tetrem, t_point start);


#endif