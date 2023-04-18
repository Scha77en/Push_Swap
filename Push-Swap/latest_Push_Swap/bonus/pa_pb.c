/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/16 21:44:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	push_to_stack(t_tavern **stack_1, t_tavern **stack_2, int ref)
{
	t_tavern	*temp;

	if (!*stack_1)
		return ;
	if (ref == 1)
		write(1, "pb\n", 3);
	else if (ref == 0)
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

// int	push(t_tavern **stacka, t_tavern **stackb)
// {
// 	t_tavern	*tmp;
// 	t_tavern	*heada;
// 	t_tavern	*headb;

// 	if (ft_lstsize(*stackb) == 0)
// 		return (1);
// 	heada = *stacka;
// 	headb = *stackb;
// 	tmp = headb;
// 	headb = headb->next;
// 	*stackb = headb;
// 	if (!heada)
// 	{
// 		heada = tmp;
// 		heada->next = NULL;
// 		*stacka = heada;
// 	}
// 	else
// 	{
// 		tmp->next = heada;
// 		*stacka = tmp;
// 	}
// 	return (0);
// }

// void	pa(t_tavern **stacka, t_tavern **stackb)
// {
// 	if (push(stacka, stackb) == 1)
// 		return ;
// 	write(2, "pa\n", 3);
// 	return ;
// }

// void	pb(t_tavern **stacka, t_tavern **stackb)
// {
// 	if (push(stackb, stacka) == 1)
// 		return ;
// 	write(2, "pb\n", 3);
// 	return ;
// }
