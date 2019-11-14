/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:50 by lseema            #+#    #+#             */
/*   Updated: 2019/05/27 20:56:48 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_sym(const char *str, size_t i)
{
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t')
			|| (str[i] == '\r') || (str[i] == '\f') || (str[i] == '\v'))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	gr;
	int		flag;

	res = 0;
	flag = 1;
	gr = 9223372036854775807 / 10;
	i = next_sym(str, 0);
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if ((res > gr || (res == gr && (str[i] - '0') > 7)) && flag == 1)
			return (-1);
		else if ((res > gr || (res == gr && (str[i] - '0') > 8)) && flag == -1)
			return (0);
		res = (res * 10) + (long long int)(str[i++] - '0');
	}
	return (res * flag);
}
