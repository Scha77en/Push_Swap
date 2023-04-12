/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:02:25 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/11 02:38:37 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_moves(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current;
	t_tavern	*best;

	current = *sb;
	// printf("all moves are set\n");
	while (*sb)
	{
		set_moves_in_a(sa, sb);
		set_moves_in_b(sb);
		best = find_best_move(sb);
		if (best->mb * best->ma > 0)
		{
			while (best->mb && best->ma && best->mb < 0 && best->ma < 0)
			{
				shift_down_stack_a_b(sa, sb);
				best->mb++;
				best->ma++;
			}
			while (best->mb && best->ma && best->mb > 0 && best->ma > 0)
			{
				shift_up_stack_a_b(sa, sb);
				best->mb--;
				best->ma--;
			}
			while (best->mb && best->mb < 0)
			{
				shift_down_stack_b(sb, 1);
				best->mb++;
			}
			while (best->ma && best->ma < 0)
			{
				shift_down_stack_a(sa, 1);
				best->ma++;
			}
			while (best->mb && best->mb > 0)
			{
				shift_up_stack_b(sb, 1);
				best->mb--;
			}
			while (best->ma && best->ma < 0)
			{
				shift_up_stack_a(sa, 1);
				best->ma--;
			}
			push_to_stack(sa, sb, 0);
		}
		if (best->mb * best->ma <= 0)
		{
			while (best->mb && best->mb > 0)
			{
				shift_up_stack_b(sb, 1);
				best->mb--;
			}
			while (best->mb && best->mb < 0)
			{
				shift_down_stack_b(sb, 1);
				best->mb++;
			}
			while (best->ma && best->ma > 0)
			{
				shift_up_stack_a(sa, 1);
				best->ma--;
			}
			while (best->ma && best->ma < 0)
			{
				shift_down_stack_a(sa, 1);
				best->ma++;
			}
			push_to_stack(sb, sa, 0);
		}
		sort_stack_a(sa);
	}
}

// void	shifting_nodes(t_tavern **sa, t_tavern **sb)

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
		// printf("%d\n", position);
		if (position > (size / 2))
				current->mb = position - size;
		else if (position <= (size / 2))
			current->mb = position;
		current = current->next;
		i--;
	}
}

void	set_moves_in_a(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current_a;
	t_tavern	*current_b;
	int			size;

	size = ft_lstsize(*sa);
	current_a = *sa;
	current_b = *sb;
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
			current_b->ma = current_b->ma - size;
		current_b = current_b->next;
		if (current_b == *sb)
			break ;
	}
}

t_tavern	*find_best_move(t_tavern **stack)
{
	t_tavern	*current;
	t_tavern	*best;
	int			moves;
	int			best_move;

	best_move = 0;
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
			best = current;
			current = current->next;
		if (current == *stack)
			break ;
	}
	return (best);
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
		if (current->content == search->content)
			break ;
		search = search->next;
	}
	return (i);
}
