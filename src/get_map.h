#ifndef GET_MAP_H
# define GET_MAP_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/fillit.h"

size_t          get_min_size(int count);
void            free_map(t_map *map);
void            update_map(t_map *map, char **rows);
static char     **make_map_str(size_t size);
t_map	        *create_map(size_t size);
t_point         del_tetrem_and_get_backpos(char c, t_map *map);
int             get_height_on_first(int *tetrem);
int             get_width_on_first(int *tetrem);
t_point         del_tetrem_and_get_newpos(char c, t_map *map);

#endif