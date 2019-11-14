/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:26:40 by lseema            #+#    #+#             */
/*   Updated: 2019/05/26 21:16:10 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	i = 0;
	if ((!dst) && (!src))
		return (dst);
	if (src >= dst)
		while (len--)
			*p_dst++ = *p_src++;
	else
	{
		p_dst = p_dst + len - 1;
		p_src = p_src + len - 1;
		while (len--)
			*p_dst-- = *p_src--;
	}
	return (dst);
}
