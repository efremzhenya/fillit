/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:11:10 by lseema            #+#    #+#             */
/*   Updated: 2019/11/22 22:12:57 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "check.h"
#include "read.h"

void	msg_error()
{
	write(1, "error\n", 6);
};

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		msg_error();
	if (!validate_file(argv[1]))
	{
		msg_error();
		return (0);
	}
	if (!(create_tetrems(fd)))
	{
		msg_error();
		return(0);
	}
	
	return (0);
}
