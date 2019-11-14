/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:45:16 by lseema            #+#    #+#             */
/*   Updated: 2019/05/26 21:21:21 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	cap(int n)
{
	size_t i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long int	i;
	char		*str;
	int			flag;

	flag = 0;
	i = cap(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[--i] = '8';
			n = -214748364;
		}
		n = -1 * n;
		flag = 1;
	}
	while (i-- >= 0)
	{
		str[i] = ((i == 0) && (flag == 1)) ? '-' : (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
