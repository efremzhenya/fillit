/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:13:08 by lseema            #+#    #+#             */
/*   Updated: 2019/05/20 17:46:24 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_p;
	unsigned char		*dst_p;

	if ((!dst) && (!src))
		return (dst);
	src_p = src;
	dst_p = dst;
	while (n-- > 0)
		*dst_p++ = *src_p++;
	return (dst);
}
