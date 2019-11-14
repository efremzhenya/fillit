/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:19:54 by lseema            #+#    #+#             */
/*   Updated: 2019/05/20 18:54:41 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s || !(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- > 0)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
