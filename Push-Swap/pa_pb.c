/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/07 16:45:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_tavern **a, t_tavern **b)
{
	t_tavern	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)-> next;
		temp -> next = *a;
		*a = temp;
		write (1, "pa\n", 3);
	}
}

void	push_to_b(t_tavern **a, t_tavern **b)
{
	t_tavern	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)-> next;
		temp -> next = *b;
		*b = temp;
		write (1, "pb\b", 3);
	}
}
