#ifndef GET_MAP_H
# define GET_MAP_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../includes/fillit.h"

char     *get_min_map(int count);
int     get_min_size(int count);
void		free_map(t_map **map);
void		update_map(t_map **map, char **rows);
static char     **make_map_str(size_t size);

#endif