/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:06:56 by lseema            #+#    #+#             */
/*   Updated: 2019/05/18 15:41:18 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	end;
	char	*dst;

	if (!s)
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	if (!(end = ft_strlen(s)))
		return (ft_strnew(0));
	end = end - 1;
	while (((s[end] == ' ') || (s[end] == '\n') || (s[end] == '\t')))
		end--;
	if (!(dst = ft_strnew(end)))
		return (NULL);
	i = 0;
	while (i <= end)
		dst[i++] = *s++;
	dst[i] = '\0';
	return (dst);
}
