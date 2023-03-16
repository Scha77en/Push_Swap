/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:12:09 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/07 16:42:33 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_down_stack_a(t_tavern **a, int n)
{
	t_tavern	*temp;
	t_tavern	*last;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	last->next = temp;
	if (n == 1)
		write (1, "rra\n", 4);
}

void	shift_down_stack_b(t_tavern **b, int n)
{
	t_tavern	*temp;
	t_tavern	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	last->next = temp;
	if (n == 1)
		write (1, "rrb\n", 4);
}

void	shift_down_stack_a_b(t_tavern **a, t_tavern **b)
{
	shift_down_stack_a(a, 0);
	shift_down_stack_b(b, 0);
	write (1, "rrr\n", 4);
}
