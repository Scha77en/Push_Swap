/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:04:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/05 16:11:04 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tavern	*feeding(char **s)
{
	t_tavern	*node;
	t_tavern	*head;
	int			i;

	head = NULL;
	i = 0;
	while (s[i])
	{
		node = ft_lstnew(s[i]);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
