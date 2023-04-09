/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/07 05:09:17 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_tavern **stack_1, t_tavern **stack_2, int ref)
{
	t_tavern	*temp;
	t_tavern	*temp2;

	if (!*stack_1)
		return ;
	if (ref)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	if (!(*stack_2))
	{
		temp = *stack_1;
		stack_check(stack_1);
		*stack_2 = temp;
		(*stack_2)->next = (*stack_2);
		(*stack_2)->previous = (*stack_2);
		return ;
	}
	temp = (*stack_1);
	stack_check(stack_1);
	temp->next = *stack_2;
	temp->previous = (*stack_2)->previous;
	(*stack_2)->previous->next = temp;
	(*stack_2)->previous = temp;
	*stack_2 = temp;
}

void	stack_check(t_tavern **stack)
{
	if ((*stack)->next == *stack)
			*stack = NULL;
	else
	{
		(*stack)->previous->next = (*stack)->next;
		(*stack)->next->previous = (*stack)->previous;
		*stack = (*stack)->next;
	}
}
