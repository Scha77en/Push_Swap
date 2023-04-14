/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:12:09 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/14 13:46:35 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	shift_down_stack_a(t_tavern **sa, int v)
{
	int		size;

	size = ft_lstsize(*sa);
	if (size <= 1)
		return ;
	*sa = (*sa)->previous;
	if (v == 1)
		write(1, "rra\n", 4);
}

void	shift_down_stack_b(t_tavern **sb, int n)
{
	int		size;

	size = ft_lstsize(*sb);
	if (size <= 1)
		return ;
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
