/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:35:30 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 23:38:13 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_tavern **sa)
{
	if ((*sa)->content > (*sa)->next->content)
		swap_a(sa, 1);
}

void	sort_three(t_tavern **sa)
{
	if ((*sa)->content > (*sa)->next->content
		&& (*sa)->content > (*sa)->next->next->content)
	{
		shift_up_stack_a(sa, 1);
		if ((*sa)->content > (*sa)->next->content)
			swap_a(sa, 1);
	}
	else if ((*sa)->content < (*sa)->next->content
		&& (*sa)->content < (*sa)->next->next->content)
	{
		if (check_args_o_o(sa))
		{
			swap_a(sa, 1);
			shift_up_stack_a(sa, 1);
		}
	}
	if ((*sa)->content < (*sa)->next->content
		&& (*sa)->content > (*sa)->next->next->content)
		shift_down_stack_a(sa, 1);
	else if ((*sa)->content > (*sa)->next->content
		&& (*sa)->content < (*sa)->next->next->content)
		swap_a(sa, 1);
}

void	sort_four(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*smallest;
	int			position;

	smallest = smallest_node(sa);
	position = node_position(smallest, sa);
	if (position > 2)
			smallest->mb = position - 4;
	else if (position <= 2)
		smallest->mb = position;
	while (smallest->mb > 0)
	{
		shift_up_stack_a(sa, 1);
		smallest->mb--;
	}
	while (smallest->mb < 0)
	{
		shift_down_stack_a(sa, 1);
		smallest->mb++;
	}
	push_to_stack(sa, sb, 1);
	sort_three(sa);
	push_to_stack(sb, sa, 0);
}

void	sort_five(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*smallest;
	int			position;

	smallest = smallest_node(sa);
	position = node_position(smallest, sa);
	if (position > 2)
			smallest->mb = position - 5;
	else if (position <= 2)
		smallest->mb = position;
	while (smallest->mb > 0)
	{
		shift_up_stack_a(sa, 1);
		smallest->mb--;
	}
	while (smallest->mb < 0)
	{
		shift_down_stack_a(sa, 1);
		smallest->mb++;
	}
	push_to_stack(sa, sb, 1);
	sort_four(sa, sb);
	push_to_stack(sb, sa, 0);
}

t_tavern	*smallest_node(t_tavern **head)
{
	t_tavern	*current;
	t_tavern	*smallest;

	current = *head;
	smallest = *head;
	while (1)
	{
		if (current->content < smallest->content)
			smallest = current;
		current = current->next;
		if (current == (*head))
			break ;
	}
	return (smallest);
}
