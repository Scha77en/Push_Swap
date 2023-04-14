/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:07:58 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/14 15:30:12 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	checking_moves(t_tavern **sa, t_tavern **sb, char *line)
{
	if (!ft_strcmp(line, "pb\n"))
		push_to_stack(sa, sb, -1);
	else if (!ft_strcmp(line, "pa\n"))
		push_to_stack(sb, sa, -1);
	else if (!ft_strcmp(line, "sa\n"))
		swap_a(sa, 0);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(sb, 0);
	else if (!ft_strcmp(line, "ss\n"))
		swap_a_b(sa, sb);
	else if (!ft_strcmp(line, "ra\n"))
		shift_up_stack_a(sa, 0);
	else if (!ft_strcmp(line, "rb\n"))
		shift_up_stack_b(sb, 0);
	else if (!ft_strcmp(line, "rr\n"))
		shift_up_stack_a_b(sa, sb);
	else if (!ft_strcmp(line, "rra\n"))
		shift_down_stack_a(sa, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		shift_down_stack_b(sb, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		shift_down_stack_a_b(sa, sb);
	else
		kay_oh();
}

int	check_stack(t_tavern **sa)
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

int	stack_length(t_tavern **sa, int size)
{
	int		n_size;

	n_size = ft_lstsize(*sa);
	if (n_size != size)
		return (1);
	return (0);
}

void	kay_oh(void)
{
	write(2, "KO\n", 3);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_tavern	*sa;
	t_tavern	*sb;
	char		*line;
	int			size;

	sa = NULL;
	sb = NULL;
	line = NULL;
	handling_errors(argc, argv, &sa);
	ft_lstadd_back_d(&sa, NULL, 0);
	size = ft_lstsize(sa);
	while (get_next_line(0, &line))
	{
		checking_moves(&sa, &sb, line);
		free(line);
	}
	if (check_stack(&sa))
		kay_oh();
	else if (stack_length(&sa, size))
		kay_oh();
	else
		write (2, "OK\n", 3);
	return (0);
}
