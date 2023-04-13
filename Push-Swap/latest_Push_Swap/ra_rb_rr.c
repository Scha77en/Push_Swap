/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:12:06 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 07:45:28 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up_stack_a(t_tavern **sa, int v)
{
	*sa = (*sa)-> next;
	if (v == 1)
		write (1, "ra\n", 3);
}

void	shift_up_stack_b(t_tavern **sb, int v)
{
	*sb = (*sb)->next;
	if (v == 1)
		write (1, "rb\n", 3);
}

void	shift_up_stack_a_b(t_tavern **sa, t_tavern **sb)
{
	shift_up_stack_a(sa, 0);
	shift_up_stack_b(sb, 0);
	write (1, "rr\n", 3);
}
