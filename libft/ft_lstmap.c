/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:01:24 by lseema            #+#    #+#             */
/*   Updated: 2019/05/22 15:36:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *cur;

	if ((!lst) || (!f))
		return (NULL);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!new)
		return (NULL);
	cur = new;
	lst = lst->next;
	while (lst != NULL)
	{
		cur->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!cur)
			return (NULL);
		lst = lst->next;
		cur = cur->next;
	}
	return (new);
}
