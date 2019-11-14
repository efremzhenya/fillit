/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:09:25 by lseema            #+#    #+#             */
/*   Updated: 2019/11/13 21:11:47 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

char     *validate_file(char *file);
int     check_tetremino(char *chr);
int		check_connections(char *chr);
int                *block_indexes(char *row);


#endif
