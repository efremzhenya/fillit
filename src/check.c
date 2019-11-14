/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:57:37 by lseema            #+#    #+#             */
/*   Updated: 2019/11/13 21:18:34 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static int    check_connects(char *row)
{
    int        j;
    int        i;
    int        touches;
    int        *b;
    
    i = 0;
    touches = 0;
    b = block_indexes(row);
    while (i < 4)
    {
        j = 0;
        while (j < 4 && (i != 3 || j != 3))
        {
            if (i == j)
                j++;
            if ((b[i] / 4 == b[j] / 4) && (abs(b[i] - b[j]) == 1))
                touches++;
            if ((b[i] % 4 == b[j] % 4) && (abs(b[i] / 4 - b[j] / 4) == 1))
                touches++;
            j++;
        }
        i++;
    }
    free(b);
    printf("%i",touches);
    return (touches == 6 || touches == 8) ? (1) : (0);
}

int                *block_indexes(char *row)
{
    int            *b_idxs;
    int            i;
    int            c;
    
    c = 0;
    i = 0;
    b_idxs = (int*)malloc(sizeof(int) * 4);
    while (i < 4)
    {
        if (row[c] == '#')
        {
            b_idxs[i] = c;
            i++;
        }
        c++;
    }
    return (b_idxs);
}

int     check_tetremino(char *chr)
{
	int i;
	int sharp_count;
	
	i = 0;
	sharp_count = 0;
    while (*chr)
    {
		i++;
        if (*chr == '#')
            sharp_count++;
        else if (!(*chr == '\n' && ((i % 5 == 0) || i == 21)) && *chr != '.')
			return (0);
		chr++;
    }
	return (sharp_count == 4);
}

char     *validate_file(char *file)
{
    	int     fd;
	char	*buf;
	int		count;

	buf = ft_strnew(21);
    if ((fd = open(file, O_RDONLY)) < 0)
		return(NULL);
	else
	{
		while ((count = read(fd, buf, 21)) == 21)
		{
			printf("%s", buf);
			if (check_tetremino(buf) && check_connects(buf))
                printf("succes!");
            else
                return (NULL);
		}
	}
	return("");
}
