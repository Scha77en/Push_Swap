/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:48:37 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 08:08:53 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_tavern	*sa;
	t_tavern	*sb;
	int			v;
	int			z;

	v = 0;
	z = 0;
	sa = NULL;
	handling_errors(argc, argv, &sa);
	ft_lstadd_back_d(&sa, NULL, 0);
	if (check_args_o_o(&sa))
	{
		if (argc <= 6)
			small_sorts(&sa, &sb);
		else
		{
			if (argc >= 500)
				v = 1;
			sort_index(&sa, &sb, v, z);
			push_from_sb(&sa, &sb);
		}
	}
	if (!check_args_o_o(&sa))
		exit(1);
	return (0);
}
