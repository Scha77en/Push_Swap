/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:51:07 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/11 02:38:17 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	largest_node(t_tavern **head, int v)
{
	t_tavern	*current;
	t_tavern	*largest;

	current = *head;
	largest = *head;
	while (1)
	{
		if (current->content > largest->content)
			largest = current;
		current = current->next;
		if (current == (*head))
			break ;
	}
	if (v == 1)
	{
		largest->value = 2;
		return ;
	}
	largest->large = 1;
}

void	smallest_node(t_tavern **head, int v)
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
	// the smallest node in the list
	if (v == 1)
	{
		smallest->value = -1;
		return ;
	}
	// the smallest node in the LIS
	if (v == 2)
	{
		smallest->value = -2;
		return ;
	}
	smallest->small = 1;
}

int	check_stack(t_tavern **stack)
{
	t_tavern	*current;

	current = (*stack);
	while (1)
	{
		if (current->value == -1)
			return (1);
		current = current->next;
		if (current == *stack)
			return (0);
	}
}

// if the return of the previous function is 1, that means stack b has the smallest
// number in the list and therefor it need to be moves to the top of stack a.
// calling the following function will do the job.

void	move_smallest(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current;
	int			size;
	int			i;
	int			moves;

	i = -1;
	size = ft_lstsize(*sb);
	current = *sb;
	sort_stack_a(sa);
	// printf("[%d] -- [%d]\n", (*sa)->content, (*sa)->value);
	if (check_smallest(sb))
	{
		while (1)
		{
			i++;
			if (current->value == -1)
			{
				if (i > (size / 2))
				{
					moves = size - i;
					while (moves)
					{
						shift_down_stack_b(sa, 1);
						moves--;
					}
				}
				else
				{
					while (i)
					{
						shift_up_stack_b(sa, 1);
						i--;
					}
				}
				push_to_stack(sb, sa, 0);
				break ;
			}
			current = current->next;
			if (current == *sa)
				break ;
		}
	}
}

void	sort_stack_a(t_tavern **sa)
{
	t_tavern	*current;
	int			moves;
	int			i;
	int			size;
	int			v;

	i = -1;
	size = ft_lstsize(*sa);
	if (check_smallest(sa))
		v = -1;
	else
	{
		smallest_node(sa, 2);
		v = -2;
	}
	current = *sa;
	while (1)
	{
		i++;
		if (current->value == v)
		{
			if (i > (size / 2))
			{
				moves = size - i;
				while (moves)
				{
					shift_down_stack_a(sa, 1);
					moves--;
				}
			}
			else
			{
				while (i)
				{
					shift_up_stack_a(sa, 1);
					i--;
				}
			}
			break ;
		}
		current = current->next;
		if (current == *sa)
			break ;
	}
}

int		check_smallest(t_tavern **stack)
{
	t_tavern	*current;

	current = *stack;
	while (1)
	{
		if (current->value == -1)
			return (1);
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (0);
}
