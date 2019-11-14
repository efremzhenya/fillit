/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:42:02 by lseema            #+#    #+#             */
/*   Updated: 2019/05/26 21:58:44 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cur;

	if (!del || !alst)
		return ;
	cur = *alst;
	while (cur != NULL)
	{
		del(cur->content, cur->content_size);
		free(cur);
		cur = cur->next;
	}
	*alst = NULL;
}
