/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:57:37 by lseema            #+#    #+#             */
/*   Updated: 2019/11/16 17:10:36 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int     get_contact(char *buff)
{
    int i;
	int count;
	
	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (i + 1 <= 18 && buff[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buff[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buff[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buff[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int     check_tetremino(char *chr)
{
	int i;
	int blocks;
	int contacts;
	
	i = 0;
	blocks = 0;
	contacts = get_contact(chr);
    while (*chr)
    {
		i++;
        if (*chr == '#')
            blocks++;
        else if (!(*chr == '\n' && (i % 5 == 0)) 
                    && (!((*chr == '.') && (i % 5 != 0))))
			return (0);
		chr++;
    }
	return (((blocks == 4) && (contacts == 6 || contacts == 8)) ? 1 : 0);
}

int     validate_file(char *file)
{
    int             fd;
	char	        *buf;
	unsigned int    count_tetrems;
    unsigned int    count_chars;
	unsigned int	is_newline;

	buf = ft_strnew(20);
    count_chars = 0;
    count_tetrems = 0;
	is_newline = 1;
    if ((fd = open(file, O_RDONLY)) < 0)
		return(0);
	else
	{
		while ((count_chars = read(fd, buf, 20)) == 20 && is_newline)
		{
			is_newline = 0;
            count_tetrems++;
			if (!check_tetremino(buf) || 
				((is_newline = read(fd, buf, 1)) == 1 && *buf != '\n'))
                return (0);
		}
        if (count_chars != 0 || is_newline || !count_tetrems || count_tetrems > 26)
            return (0);
	}
	return(1);
}