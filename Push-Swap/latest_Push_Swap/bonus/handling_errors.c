/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:14:39 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/14 00:28:25 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	check_length(char *str)
{
	if (ft_atoi(str) > (long)2147483647 || ft_atoi(str) < (long)(-2147483648)
		|| ft_strlen(str) > 11)
	{
		write (2, "Error\n", 6);
		exit(11);
	}
}

void	handling_errors(int argc, char *argv[], t_tavern **sa)
{
	int			i;
	int			j;
	char		**len;
	t_tavern	*tmp;

	i = 0;
	while (argv[++i])
		analyse_arg(argv[i]);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		len = ft_split(argv[i], ' ');
		while (len[++j])
		{
			check_length(len[j]);
			tmp = ft_lstnew_d(ft_atoi(len[j]));
			ft_lstadd_back_d(sa, tmp, 1);
		}
	}
	check_twin(sa, tmp);
}

void	check_twin(t_tavern **sa, t_tavern *tmp)
{
	t_tavern	*tmp2;

	tmp2 = *sa;
	while (tmp2)
	{
		tmp = tmp2;
		while (tmp -> previous)
		{
			tmp = tmp -> previous;
			if (tmp2->content == tmp -> content)
				error_out();
		}
		tmp = tmp2;
		while (tmp -> next)
		{
			tmp = tmp -> next;
			if (tmp2->content == tmp -> content)
				error_out();
		}
		tmp2 = tmp2->next;
	}
	tmp = NULL;
}

void	analyse_arg(char *str)
{
	long		i;
	long		trigger;

	i = -1;
	trigger = 0;
	if ((str[++i] == '-' || str[i] == '+'))
			trigger++;
	if (!str[i])
		error_out();
	i--;
	check_str(str, i, trigger);
}

void	check_str(char *str, long i, long trigger)
{
	long	j;

	j = 0;
	while (str[++i])
	{
		if (((str[i] < '0' || str[i] > '9') && str[i] != ' '
				&& str[i] != '-' && str[i] != '+'))
			error_out();
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (str[i - 1] != ' ' && str[i - 1] != '\0')
				trigger = 3;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				error_out();
		}
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		if (str[i] == ' ' && str[i + 1] == '\0' && j == 0)
			error_out();
		if (trigger > 2)
			error_out();
	}
}
