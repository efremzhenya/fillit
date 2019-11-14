/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:17:55 by lseema            #+#    #+#             */
/*   Updated: 2019/05/22 20:39:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t k;
	size_t end_str;

	k = 0;
	while (dst[k] && k < size)
		k++;
	end_str = k;
	if (size)
		while ((k < size - 1) && (src[k - end_str]))
		{
			dst[k] = src[k - end_str];
			k++;
		}
	if (end_str < size)
		dst[k] = '\0';
	k = 0;
	while (src[k])
		k++;
	return (end_str + k);
}
