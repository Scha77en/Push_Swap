/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:07:35 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/08 18:09:20 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tavern	*ft_lstnew(void *content)
{
	t_tavern	*node1;

	node1 = (t_tavern *)malloc(sizeof(t_tavern));
	if (!node1)
		return (0);
	node1 -> content = content;
	node1 -> next = NULL;
	return (node1);
}

void	ft_lstadd_back(t_tavern **lst, t_tavern *new)
{
	t_tavern	*lnode;

	if (!new)
		return ;
	while (!*lst)
	{
		*lst = new;
		return ;
	}
	lnode = ft_lstlast(*lst);
	lnode -> next = new;
}

t_tavern	*ft_lstlast(t_tavern *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
