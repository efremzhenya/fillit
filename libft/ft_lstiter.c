/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:00:15 by lseema            #+#    #+#             */
/*   Updated: 2019/05/26 22:02:20 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current);
		current = current->next;
	}
}
