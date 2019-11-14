/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:51:22 by lseema            #+#    #+#             */
/*   Updated: 2019/05/20 18:41:53 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	if (!(p = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
