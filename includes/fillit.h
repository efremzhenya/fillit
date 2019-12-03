/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:15:58 by lseema            #+#    #+#             */
/*   Updated: 2019/12/03 22:05:32 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>

typedef struct s_tetrem
{
    int             *tetrem;
    char            c;
    struct s_tetrem *next;
}                   t_tetrem;

typedef struct	s_map
{
    char		**map;
	size_t		size;
}				t_map;

typedef struct	s_point
{
    int		    x;
	int		    y;
}				t_point;

#endif
