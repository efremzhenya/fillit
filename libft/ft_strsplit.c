/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:13:41 by lseema            #+#    #+#             */
/*   Updated: 2019/05/27 21:39:43 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_words(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (str[i] && (str[i] != c) && (str[i + 1] != c) && (str[i + 1]))
		count++;
	while (str[i])
	{
		if ((str[i] == c) && (str[i + 1] != c) && (str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	ft_splitstr(char **arr, const char *s, char d, size_t len)
{
	size_t	j;
	size_t	count;
	size_t	wlen;

	count = 0;
	j = 0;
	while (count < len)
	{
		wlen = 0;
		while (s[j] == d && s[j])
			j++;
		while (s[j] != d && s[j])
		{
			wlen++;
			j++;
		}
		if (!(arr[count] = ft_strsub(&s[j - wlen], 0, wlen)))
			return (0);
		count++;
	}
	arr[count] = NULL;
	return (1);
}

char		**ft_strsplit(char const *str, char c)
{
	size_t	l;
	char	**arr;

	if (!str)
		return (NULL);
	l = ft_num_words(str, c);
	if (!(arr = ((char **)ft_memalloc(sizeof(char *) * l + 1))))
		return (NULL);
	if (ft_splitstr(arr, str, c, l))
		return (arr);
	else
		ft_memdel((void **)arr);
	return (arr);
}
