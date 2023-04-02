/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:08:50 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/02 22:49:24 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_d(t_tavern **lst, t_tavern *new, int v)
{
	t_tavern	*lnode;

	if (v == 0)
	{
		lnode = ft_lstlast(*(lst));
		lnode -> next = *lst;
		(*lst)-> previous = lnode;
		return ;
	}
	if (!new)
		return ;
	while (!(*lst))
	{
		*lst = new;
		return ;
	}
	lnode = ft_lstlast(*(lst));
	lnode -> next = new;
	new -> previous = lnode;
}

t_tavern	*ft_lstnew_d(int content)
{
	t_tavern	*node1;

	node1 = (t_tavern *)malloc(sizeof(t_tavern));
	if (!node1)
		return (NULL);
	node1 -> content = content;
	node1 -> next = NULL;
	node1 -> previous = NULL;
	return (node1);
}

t_tavern	*ft_lstlast(t_tavern *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_tavern *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
