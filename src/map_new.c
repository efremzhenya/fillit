/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:47:33 by atfoster          #+#    #+#             */
/*   Updated: 2019/11/24 11:51:59 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

char     *get_min_map(int count)
{
    char    *map;
    int     i;
    int     k;

	i = 0;
    k = get_min_size(count);
    if (!(map = ft_strnew(k * (k + 1))))
        return (NULL);
    while ((k * (k + 1)) > i)
    {
        map[i] = ((i - k) % (k + 1) || ((i - k) < 0)) ? '.' : '\n';
        i++;
    }
    map[i] = '\0';
    return(map);
}

int     get_min_size(int count)
{
    if (count == 1)
        return (2);
    else if (count == 2)
        return (3); 
    else if (count == 3 || count == 4)
        return(4); 
    else if (count == 5 || count == 6)
        return(5); 
    else if (count == 7 || count == 8 || count == 9)
        return(6);
    else if (count == 10 || count == 11 || count == 12)
        return(7); 
    else if (count == 13 || count == 14 || count == 15 || count == 16)
        return(8); 
    else if (count == 17 || count == 18 || count == 19 || count == 20)
        return(9);
    else if (count == 21 || count == 22 || count == 23 || count == 24 
        || count == 25)
        return(10);
    else if (count == 26)
        return(11);
    return (0);
}

/*For check get_min_map*/

// int main()
// {
//     int i;
//     char *p;
//     i = 0;
//     while (i < 27){
//         printf("size: %i\n",i);
//         p = get_min_map(i++);
//         while (*p)
//         {
//             write (1, &(*p), 1);
//             p++;
//         }
//         printf("________\n");
//     }
//     return (0);
// }