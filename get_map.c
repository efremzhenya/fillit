/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atfoster <atfoster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:47:33 by atfoster          #+#    #+#             */
/*   Updated: 2019/11/19 21:28:39 by atfoster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int     get_map(unsigned int     tetrem)
{
    char            *map;
    unsigned int     i;
    unsigned int     k;
    char            *x;
    
	i = 0;
    k = 0;
    if (tetrem == 1)
        k = 2;
    else if (tetrem == 2)
        k = 3; 
    else if (tetrem == 3 || tetrem == 4)
        k = 4; 
    else if (tetrem == 5 || tetrem == 6)
        k = 5; 
    else if (tetrem == 7 || tetrem == 8 || tetrem == 9)
        k = 6;
    else if (tetrem == 10 || tetrem == 11 || tetrem == 12)
        k = 7; 
    else if (tetrem == 13 || tetrem == 14 || tetrem == 15 || tetrem == 16)
        k = 8; 
    else if (tetrem == 17 || tetrem == 18 || tetrem == 19 || tetrem == 20)
        k = 9;  
    else if (tetrem == 21 || tetrem == 22 || tetrem == 23 || tetrem == 24 
        || tetrem == 25)
        k = 10;
    else if (tetrem == 26)
        k = 11;          
    map = ft_strnew(k * (k + 1));
    while ((k * (k + 1)) > i++)
    {
        if (!(i % (k + 1) == 0 ))
            map[i] = '.';
        else
            map[i] = '\n';
        //write(1, &map[i], 1);
    }
//    i = 0;
    x = ft_strdup(map);  
    free(map);
    map = NULL;
//    printf("строка :\n%s\n", x);
    return(x[i]); 
}

int     main()
{
	unsigned int		n;
	n = 1;
	get_map(n);
    return(0);
}