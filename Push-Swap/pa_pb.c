/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/07 01:50:47 by aouhbi           ###   ########.fr       */
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
		puts("pb");
	else
		puts("pa");
	if (!(*stack_2))
	{
		temp = *stack_1;
		if ((*stack_1)->next == *stack_1)
			*stack_1 = NULL;
		else
		{
			(*stack_1)->previous->next = (*stack_1)->next;
			(*stack_1)->next->previous = (*stack_1)->previous;
			*stack_1 = (*stack_1)->next;
		}
		*stack_2 = temp;
		(*stack_2)->next = (*stack_2);
		(*stack_2)->previous = (*stack_2);
		return ;
	}
	temp = (*stack_1);
	if ((*stack_1)->next == *stack_1)
		*stack_1 = NULL;
	else
	{
		(*stack_1)->previous->next = (*stack_1)->next;
		(*stack_1)->next->previous = (*stack_1)->previous;
		*stack_1 = (*stack_1)->next;
	}
	temp->next = *stack_2;
	temp->previous = (*stack_2)->previous;

	(*stack_2)->previous->next = temp;
	(*stack_2)->previous = temp;
	*stack_2 = temp;
	// temp -> next = *stack_2;
	// temp->previous = (*stack_2)->previous;
	// (*stack_2)->previous = temp;
	// *stack_2 = temp;
	// temp2 = (*stack_1); // fix the stack a, the push is successful but the cleanup is not working yet;

}

