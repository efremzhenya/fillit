/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:38:53 by atfoster          #+#    #+#             */
/*   Updated: 2019/12/07 18:57:26 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include <stdio.h>

size_t     get_min_size(int count)
{
    if (count == 1)
        return (2);
    else if (count == 2)
        return (3); 
    else if (count == 3 || count == 4)
        return(4); 
    else if (count == 5 || count == 6)
        return(5); 
    else if (count == 7 || count == 8 || count == 9)
        return(6);
    else if (count == 10 || count == 11 || count == 12)
        return(7); 
    else if (count == 13 || count == 14 || count == 15 || count == 16)
        return(8); 
    else if (count == 17 || count == 18 || count == 19 || count == 20)
        return(9);
    else if (count == 21 || count == 22 || count == 23 || count == 24 
        || count == 25)
        return(10);
    else if (count == 26)
        return(11);
    return (0);
}

void		free_map(t_map *map)
{
	size_t row;

	if (!map)
		return ;
	row = 0;
	while (row < map->size)
		ft_strdel(&(map->map[row++]));
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
}

t_point		update_map(t_map *map)
{
	size_t row;
    t_point point;

	row = map->size + 1;
	free_map(map);
	map->map = make_map_str(row);
    map->size = row;
    point.y = 0;
    point.x = 0;
    return point;
}

t_map	*create_map(size_t size)
{
	t_map *map;
	
	if ((map = (t_map *)ft_memalloc(sizeof(*map))))
	{
		if (!(map -> map = make_map_str(size)))
		{
			free(map);
			return (NULL);
		}
		map->size = size;
	}
	return (map);
}

static char     **make_map_str(size_t size)
{
    char    **map;
    size_t  i;
    
    if ((map = (char **)malloc((sizeof(char *) * (size)))))
    {
        i = 0;
        while (i < size)
        {
            if (!(map[i] = (char *)malloc(sizeof(char) * (size + 2))))
            {
                while (--i)
                    ft_strdel(&map[i]);
                free(map);
                map = NULL;
                return (map);
            }
            ft_memset(map[i], '.', size);
            *(map[i] + size) = '\n';
            *(map[i] + size + 1) = '\0';
            i++;
        }
    }
    return (map);
}