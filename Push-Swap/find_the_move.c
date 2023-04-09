/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:02:25 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/09 06:46:12 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_moves(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current;
	t_tavern	*best;

	current = *sb;
	set_moves_in_a(sa, sb);
	while (1)
	{
		set_moves_in_b(current);
		current = current->next;
		if (current == *sb)
			break ;
	}
}

void	set_moves_in_b(t_tavern **stack)
{
	t_tavern	*current;
	int			position;
	int			size;

	size = ft_lstsize(*sb);
	current = *stack;
	while (1)
	{
		position = node_position(current, stack);
		if (position > (size / 2))
				current->mb = position - size;
		else
			current->mb = position;
		current = current->next;
		if (current == *stack)
			break ;
	}
}

void	set_moves_in_a(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current_a;
	t_tavern	*current_b;
	int			size;

	size = ft_lstsize(*sa);
	current_a = sa;
	current_b = sb;
	while (1)
	{
		current_b->ma = 0;
		while (1)
		{
			if (current_b->content > current_a->content)
			{
				current_a = current_a->next;
				current_b->ma++;
			}
			else
				break ;
		}
		if (current_b->ma > (size / 2))
			current_b->ma = current->ma - size;
		current_b = current_b->next;
		if (current_b == *sb)
			break ;
	}
}

void	find_best_move(t_tavern **stack)
{
	t_tavern	*current;
	t_tavern	*best;
	int			moves;
	int			best_move;

	current = *stack;
	best = *stack;
	while (1)
	{
		if (current->ma < 0)
			moves = (current->ma * -1) + current->mb;
		else if (current->mb < 0)
			moves = (current->mb * -1) + current->ma;
		else if (current->ma < 0 && current->mb < 0)
			moves = (current->ma * -1) + (current->mb * -1);
		if (best_move > moves)
			best_move = moves;
	}
}

// probably you should give the nodes an index to indicate what
// node is the best one using indexes.

int	node_position(t_tavern *current, t_tavern **stack)
{
	t_tavern	*search;
	int			i;

	i = -1;
	search = *stack;
	while (1)
	{
		i++;
		if (current->content == stack->content)
			break ;
		search = search->next;
	}
	return (i);
}
