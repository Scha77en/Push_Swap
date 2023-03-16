/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:25:46 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/13 16:33:46 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long		i;
	long		ishara;
	long		res;

	i = 0;
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

// long	ft_atoi(const char *str)
// {
// 	long		i;
// 	long		ishara;
// 	long		res;

// 	i = -1;
// 	ishara = 1;
// 	res = 0;
// 	if ((str[++i] == '-' || str[i] == '+'))
// 	{
// 		if (str[i] == '-')
// 			ishara *= -1;
// 			i++;
// 	}
// 	i--;
// 	while (str[++i])
// 	{
// 		if (str[i] >= '0' && str[i] <= '9')
// 			res = res * 10 + (str[i] - '0');
// 		else
// 		{
// 			write(2, "Error\n", 6); // the \n does not show up in the output when i use the stderr, but it does show up when i use stdout, search why?
// 			exit(0);
// 		}
// 	}
// 	return (ishara * res);
// }

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	printf("%ld", ft_atoi("++45465"));
// }
