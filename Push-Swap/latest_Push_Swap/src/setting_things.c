/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:02:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/15 04:47:22 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_index(t_tavern **sa, t_tavern **sb, int v)
{
	t_tavern	*head;
	int			i;
	int			size;
	int			z;

	z = 0;
	size = ft_lstsize(*sa);
	i = 0;
	head = min_value(sa);
	while (size != 0)
	{
		head->value = i++;
		head = min_value(sa);
		size--;
	}
	pushing_to_sb(sa, sb, v, z);
}

t_tavern	*min_value(t_tavern	**sa)
{
	t_tavern	*min;
	t_tavern	*current;

	if (!*sa)
		return (NULL);
	current = *sa;
	min = NULL;
	while (1)
	{
		if ((current->value == -2)
			&& (min == NULL || current->content < min->content))
		min = current;
		current = current->next;
		if (current == *sa)
			break ;
	}
	return (min);
}

void	pushing_to_sb(t_tavern **sa, t_tavern **sb, int v, int z)
{
	t_tavern	*current;
	int			t;

	z = 0;
	if (v == 0)
		t = 16;
	if (v == 1)
		t = 34;
	while (*sa)
	{
		current = *sa;
		if (current->value <= z)
		{
			push_to_stack(sa, sb, 1);
			z++;
		}
		else if (current->value < z + t)
		{
			push_to_stack(sa, sb, 1);
			shift_up_stack_b(sb, 1);
			z++;
		}
		else
			shift_up_stack_a(sa, 1);
	}
}

void	push_from_sb(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*largest;
	int			size;
	int			position;

	size = ft_lstsize(*sb);
	while (size)
	{
		largest = largest_node(sb);
		position = node_position(largest, sb);
		if (position > (size / 2))
				largest->mb = position - size;
		else if (position <= (size / 2))
			largest->mb = position;
		push_to_s(sa, sb, largest);
		size--;
	}
	exit(0);
}

void	set_moves_in_b(t_tavern **stack)
{
	t_tavern	*current;
	int			position;
	int			size;
	int			i;

	size = ft_lstsize(*stack);
	i = ft_lstsize(*stack);
	current = *stack;
	while (i)
	{
		position = node_position(current, stack);
		if (position > (size / 2))
				current->mb = position - size;
		else if (position <= (size / 2))
			current->mb = position;
		current = current->next;
		i--;
	}
}
