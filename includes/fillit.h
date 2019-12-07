/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:15:58 by lseema            #+#    #+#             */
/*   Updated: 2019/12/07 23:20:54 by lseema           ###   ########.fr       */
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

t_point    del_tetrem(char c, t_map *map, int y, int x);
void        free_list(t_tetrem *head);
t_point     sizes(int *tetrem);
t_point     get_position(int y, int x, t_map *map);
int     get_min_x(char *tetrem);


#endif
