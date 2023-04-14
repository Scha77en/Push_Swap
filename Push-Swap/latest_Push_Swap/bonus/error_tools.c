/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:48:37 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/14 15:40:34 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	error_out(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
