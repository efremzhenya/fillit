/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:11:10 by lseema            #+#    #+#             */
/*   Updated: 2019/12/07 22:52:34 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "check.h"
#include "read.h"
#include "solve.h"
#include "get_map.h"

int		msg_error()
{
	write(1, "error\n", 6);
	return (0);
};

int		msg_err_nofile()
{
	write(1, "usage: fillit input_file\n", 25);
	return (0);
};

void    print_map(t_map *map)
{
    int i;

    i = 0;
    while (map->size > i)
        ft_putstr(map->map[i++]);
}

int		main(int argc, char **argv)
{
	int 		fd;
	size_t 		count;
	t_tetrem 	*tetrems;
	t_map		*map;
	t_point		start;

	if (argc != 2)
		return msg_err_nofile();
	if (((fd = open(argv[1], O_RDONLY)) < 0) || !(count = validate_file(argv[1]))
		|| !(tetrems = create_tetrems(fd, 'A')))
		return msg_error();
	map = create_map(get_min_size(count));
	start.x = 0;
	start.y = 0;
	solver(map, tetrems, tetrems, tetrems, start);
	free_list(tetrems);
	tetrems = NULL;
	print_map(map);
	free_map(map);
	map = NULL;
	return (0);
}
