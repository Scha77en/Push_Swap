/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:02:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 07:25:17 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_tavern **sa, t_tavern **sb, int v)
{
	t_tavern    *head;
    int			i;
    int			size;

	size = ft_lstsize(*sa);
    i = 0;
	// printf("here\n");
    head = min_value(sa);
    while (size != 0)
    {
        head->value = i++;
        head = min_value(sa);
		size--;
    }
	pushing_to_sb(sa, sb, v);
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

void	pushing_to_sb(t_tavern **sa, t_tavern **sb, int v)
{
	t_tavern	*current;
	int			i;
	int			t;

	i = 0;
	if (v == 0)
		t = 16;
	if (v == 1)
		t = 34;
	while (*sa)
	{
		current = *sa;
		if (current->value <= i)
		{
			push_to_stack(sa, sb, 1);
			i++;
		}
		else if (current->value < i + t)
		{
			push_to_stack(sa, sb, 1);
			shift_up_stack_b(sb, 1);
			i++;
		}
		else
			shift_up_stack_a(sa, 1);
		// printf("current->value : %d\n", current->value);
	}
}

void	push_from_sb(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current;
	t_tavern	*largest;
	int			size;
	int			position;

	current = *sb;
	size = ft_lstsize(*sb);
	while (size)
	{
		largest = largest_node(sb);
		// printf("largest node : [%d]\n", largest->content);
		position = node_position(largest, sb);
		// printf("node position : [%d]\n", position);
		
		if (position > (size / 2))
				largest->mb = position - size;
		else if (position <= (size / 2))
			largest->mb = position;
		push_to_s(sa, sb, largest);
		size--;
	}
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
		// printf("%d\n", position);
		if (position > (size / 2))
				current->mb = position - size;
		else if (position <= (size / 2))
			current->mb = position;
		current = current->next;
		i--;
	}
}

int	main(int argc, char *argv[])
{
	t_tavern	*sa;
	t_tavern	*sb;
	int			i;
	// t_tavern	*current;
	// t_tavern	*current2;
	int			v;

	v = 0;
	sa = NULL;
	handling_errors(argc, argv, &sa);
	ft_lstadd_back_d(&sa, NULL, 0);
	// current = sa;
	// while (1)
	// {
	// 	printf("[%d]\n", current->content);
	// 	current = current->next;
	// 	if (current == sa)
	// 		break ;
	// }
	// // puts("out");
	// current = sa;
	// puts("------sa------");
	// while (1)
	// {
	// 	printf("content [%d] -> value [%d]\n", current->content, current->value);
	// 	current = current->next;
	// 	if (current == sa)
	// 		break ;
	// }
	if (check_args_o_o(&sa))
	{
		if (argc <= 6)
			small_sorts(&sa, &sb);
		else
		{
			if (argc >= 500)
				v = 1;
			sort_index(&sa, &sb, v);
		// // puts("out 2");
		// puts("------sa after pushing to sb------");
		// current = sa;
		// while (1)
		// {
		// 	if (!current)
		// 	{
		// 		printf("stack a is empty\n");
		// 		break ;
		// 	}
		// 	printf("content [%d] -> value [%d]\n", current->content, current->value);
		// 	current = current->next;
		// 	if (current == sa)
		// 		break ;
		// }
		// current2 = sb;
		// puts("------sb------");
		// while (1)
		// {
		// 	printf("content [%d] -> value [%d]\n", current2->content, current2->value);
		// 	current2 = current2->next;
		// 	if (current2 == sb)
		// 		break ;
		// }
			push_from_sb(&sa, &sb);
		// current = sa;
		// puts("------sa------");
		// while (1)
		// {
		// 	if (!current)
		// 	{
		// 		printf("stack a is empty\n");
		// 		break ;
		// 	}
		// 	printf("content [%d] -> value [%d]\n", current->content, current->value);
		// 	current = current->next;
		// 	if (current == sa)
		// 		break ;
		// }
		}
	}
	if (!check_args_o_o(&sa))
		exit(1);
	return (0);
}