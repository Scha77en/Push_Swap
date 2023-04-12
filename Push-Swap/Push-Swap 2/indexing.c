/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:02:57 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/12 22:43:47 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_tavern **sa, t_tavern **sb)
{
	t_tavern    *head;
    int			i;
    int			size;

	size = ft_lstsize(*sa);
    i = 0;
    head = min_value(sa);
    while (size != 0)
    {
        head->value = i++;
        head = min_value(sa);
		size--;
    }
	pushing_to_sb(sa, sb);
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

void	pushing_to_sb(t_tavern **sa, t_tavern **sb)
{
	t_tavern	*current;
	int			i;
	int			t;

	i = 0;
	t = 19;
	current = *sa;
	while (*sa)
	{
		if (current->value <= i)
		{
			push_to_stack(sa, sb, 0);
			i++;
		}
		else if (current->value < i + t)
		{
			push_to_stack(sa, sb, 0);
			shift_up_stack_b(sb, 1);
			i++;
		}
		else
			shift_up_stack_a(sa, 1);
	}
}

int	main(int argc, char *argv[])
{
	t_tavern	*sa;
	t_tavern	*sb;
	t_tavern	*current;
	t_tavern	*current2;

	sa = NULL;
	handling_errors(argc, argv, &sa);
	ft_lstadd_back_d(&sa, NULL, 0);
	current = sa;
	while (1)
	{
		printf("[%d]\n", current->content);
		current = current->next;
		if (current == sa)
			break ;
	}
	puts("out");
	current = sa;
	puts("------sa------");
	while (1)
	{
		printf("content [%d] -> value [%d]\n", current->content, current->value);
		current = current->next;
		if (current == sa)
			break ;
	}
	sort_index(&sa, &sb);
	puts("out 2");
	puts("------sa after pushing to sb------");
	current = sa;
	while (1)
	{
		if (!current)
		{
			printf("stack a is empty\n");
			break ;
		}
		printf("content [%d] -> value [%d]\n", current->content, current->value);
		current = current->next;
		if (current == sa)
			break ;
	}
	current2 = sb;
	puts("------sb------");
	while (1)
	{
		printf("content [%d] -> value [%d]\n", current2->content, current2->value);
		current2 = current2->next;
		if (current2 == sb)
			break ;
	}
	return (0);
}