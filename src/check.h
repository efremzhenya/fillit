/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:09:25 by lseema            #+#    #+#             */
/*   Updated: 2019/12/07 21:50:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

ssize_t     validate_file(char *file);
int     check_tetremino(char *chr);
int     get_contact(char *buff);
ssize_t		validate_tetrems(int fd);

#endif
