/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:11:10 by lseema            #+#    #+#             */
/*   Updated: 2019/12/07 18:03:25 by lseema           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int 		fd;
	int 		count_tetrems;
	size_t 		count;
	t_tetrem 	*tetrems;
	t_map		*t_map;

	if (argc != 2)
		return msg_err_nofile();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return msg_error();
	if (!(count_tetrems = validate_file(argv[1])))
		return msg_error();
	if (!(tetrems = create_tetrems(fd)))
		return msg_error();
	count = get_min_size(count_tetrems);
	solver(create_map(count), tetrems);
	free_list(tetrems);
	return (0);
}
