/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:12:09 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/06 23:54:05 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	shift_down_stack_a(t_tavern **a, int n)
// {
// 	t_tavern	*prev;
// 	t_tavern	*curr;

// 	if (*a == NULL || (*a)->next == *a)
// 		return ;
// 	prev = *a;
// 	curr = *a;
// 	while (curr->next != *a)
// 	{
// 		prev = curr;
// 		curr = curr->next;
// 	}
//     prev->next = curr->next;
// 	curr->next = *a;
// 	*a = curr;
// 	if (n == 1)
// 		write (1, "rra\n", 4);
// }

void	shift_down_stack_a(t_tavern **sa, int v)
{
	*sa = (*sa)->previous;
	if (v == 1)
		write(1, "rra\n", 4);
}

void	shift_down_stack_b(t_tavern **sb, int n)
{
	*sb = (*sb)->previous;
	if (n == 1)
		write (1, "rrb\n", 4);
}

void	shift_down_stack_a_b(t_tavern **sa, t_tavern **sb)
{
	shift_down_stack_a(sa, 0);
	shift_down_stack_b(sb, 0);
	write (1, "rrr\n", 4);
}
