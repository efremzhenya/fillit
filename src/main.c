/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:11:10 by lseema            #+#    #+#             */
/*   Updated: 2019/12/07 17:53:59 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "check.h"
#include "read.h"
#include "solve.h"
#include "get_map.h"

void	msg_error()
{
	write(1, "error\n", 6);
};

int		main(int argc, char **argv)
{
	int 		fd;
	int 		count_tetrems;
	size_t 		count;
	t_tetrem 	*tetrems;
	t_map		*t_map;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		msg_error();
	if (!(count_tetrems = validate_file(argv[1])))
	{
		msg_error();
		return (0);
	}
	if (!(tetrems = create_tetrems(fd)))
	{
		msg_error();
		return(0);
	}
	count = get_min_size(count_tetrems);
	solver(create_map(count), tetrems);
	free_list(tetrems);
	return (0);
}
