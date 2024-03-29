/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:51:07 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/16 21:28:56 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_position(t_tavern *current, t_tavern **stack)
{
	t_tavern	*search;
	int			i;

	i = -1;
	search = *stack;
	while (1)
	{
		i++;
		if (current->content == search->content)
			break ;
		search = search->next;
	}
	return (i);
}

t_tavern	*largest_node(t_tavern **sb)
{
	t_tavern	*current;
	t_tavern	*largest;

	current = *sb;
	largest = *sb;
	while (1)
	{
		if (current->value > largest->value)
			largest = current;
		current = current->next;
		if (current == (*sb))
			break ;
	}
	return (largest);
}

void	push_to_s(t_tavern **sa, t_tavern **sb, t_tavern *largest)
{
	while (largest->mb && largest->mb > 0)
	{
		shift_up_stack_b(sb, 1);
		largest->mb--;
	}
	while (largest->mb && largest->mb < 0)
	{
		shift_down_stack_b(sb, 1);
		largest->mb++;
	}
	pa(sb, sa);
}

int		check_args_o_o(t_tavern **sa)
{
	t_tavern	*current;

	current = *sa;
	while (1)
	{
		if (current->content > current->next->content)
			return (1);
		current = current->next;
		if (current->next == *sa)
			break ;
	}
	return (0);
}

void	small_sorts(t_tavern **sa, t_tavern **sb)
{
	int		size;

	size = ft_lstsize(*sa);
	if (size < 2)
		exit(1);
	else if (size == 2)
		sort_two(sa);
	else if (size == 3)
		sort_three(sa);
	else if (size == 4)
		sort_four(sa, sb);
	else if (size == 5)
		sort_five(sa, sb);
}