/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:48:37 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 07:54:12 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

size_t	ft_strlen_d(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[++j])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
	}
	return (i);
}

long	ft_atoi(char *str)
{
	long		i;
	long		ishara;
	long		res;

	i = 0;
	if (!str)
		return (0);
	ishara = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ishara *= -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (ishara * res);
}

void	error_out(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
