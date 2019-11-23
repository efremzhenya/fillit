/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:15:58 by lseema            #+#    #+#             */
/*   Updated: 2019/11/23 20:27:29 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>

typedef struct s_tetrem
{
    int            *tetrem;
    char            c;
    struct s_tetrem *next;
}                   t_tetrem;

#endif
