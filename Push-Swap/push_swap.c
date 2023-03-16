/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:48:37 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/15 17:31:31 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_length(char *str)
{
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648
		|| ft_strlen(str) > 10)
	{
		write (2, "Error\n", 6);
		exit(11);
	}
}

void	handling_errors(int argc, char *argv[])
{
	int	i;
	int	j;

	printf("[%d]\n", argc);
	i = 0;
	while (argv[++i])
		analyse_arg(argv[i]);
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[++j])
		{
			// printf("%s", argv[++i]);
			check_length(argv[j]);
			if (i == j)
			{
				j++;
				if (!argv[j])
					return ;
			}
			printf("%s -- %s\n", argv[i], argv[j]);
			printf("%ld\n", ft_atoi(argv[j]));
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error_out();
			// if (ft_strlen(argv[i] > 10))
			// 	if ();
		}
	}
}

void	error_out(void)
{
	write (2, "Error\n", 6);
	exit(100);
}

void	analyse_arg(char *str)
{
	long		i;
	long		j;
	long		trigger;

	i = -1;
	j = 0;
	trigger = 0;
	if ((str[++i] == '-' || str[i] == '+'))
			trigger++;
	if (!str[i])
		error_out();
	i--;
	// printf("|%c|\n", str[++i]);
	while (str[++i])
	{
		if (((str[i] < '0' || str[i] > '9') && str[i] != ' '
				&& str[i] != '-' && str[i] != '+'))
			error_out();
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (str[i - 1] != ' ' && str[i - 1] != '\0' && (str[i + 1] < '0' || str[i + 1] > '9'))
				trigger++;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				error_out();
		}
		// if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == ' '
		// 		|| str[i + 1] == '\0' || str[i + 1 == '-'
		// 			&& str[i + 1] == '+']))
		printf("|||%ld|||\n", trigger);
		printf("|%c|\n", str[i]);
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		if (str[i] == ' ' && str[i + 1] == '\0' && j == 0)
			error_out();
		if (trigger > 2)
			error_out();
	}
}

size_t	ft_strlen(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	printf("string = %s\n", s);
	while (s[++j])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		printf("character = %c\n", s[j]);
	}
	printf("length = %d\n", i);
	return (i);
}

// void	analyse_arg2(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 		printf("%c -- %c\n", str[i], str[j]);
// 	while (str[++i])
// 	{
// 		j = 1;
// 		if (i == j)
// 		{
// 			j++;
// 			if (!str[j])
// 				return ;
// 		}
// 		if (str[i] == str[j] || ft_atoi(&str[j]) > INT_MAX
// 			|| ft_atoi(&str[j]) < INT_MIN)
// 			error_out();
// 	}
// }

// int	handling_errors(int argc, char *argv[])
// {
// 	int	i;
// 	int	j;

// 	printf("[%d]\n", argc);
// 	i = 0;
// 	while (++i < argc)
// 	{
// 		printf("--- value [i]: %d\n", i);
// 		j = 0;
// 		while (++j < argc)
// 			analyse_arg(argv[j]);
// 		j = 0;
// 		while (++j < argc)
// 		{
// 			if (i == j)
// 			{
// 				j++;
// 				if (!argv[j])
// 					return (0);
// 			}
// 			printf("%s -- %s\n", argv[i], argv[j]);
// 			if (*argv[i] == *argv[j] || ft_atoi(argv[j]) > INT_MAX
// 				|| ft_atoi(argv[j]) < INT_MIN)
// 			{
// 				write(2, "Error\n", 6);
// 				exit(0);
// 			}
// 		}
// 	}
// 	return (0);
// }

// void    check_arg(char *s)
// {
//     int    i;
//     int    var;

//     i = 0;
//     var = 0;
//     while (s[i])
//     {
//         if ((s[i] < '0' || s[i] > '9')
//             && (s[i] != ' ' && s[i] != '-' && s[i] != '+'))
//             ft_error();
//         if ((s[i] >= '0' && s[i] <= '9')
//             || (s[i] == ' ' || s[i] == '-' || s[i] == '+'))
//             if ((s[i] == '-' || s[i] == '+'))
//                 var++;
//         if ((s[i] == '-' || s[i] == '+') && (s[i + 1] == '\0'
//                 || s[i + 1] == ' '))
//             var++;
//         i++;
//     }
//     if (var > 1)
//         ft_error();
// }


long	ft_atoi(char *str)
{
	long		i;
	long		ishara;
	long		res;

	// printf("\nhe got out\n");
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

//"-9-9" 	Error
//"- 9" 	Error
//"-9 -8"	none

// create a function that stores the arguments into a 2D array.
// char	**storing(int i, char *s[])
// {
// 	t_tavern	*slst;

// 	arr = malloc(i - 1 * sizeof(s[0]));
// 	if (!arr)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		arr[i + 1] = s[i + 1];
// 		i++;
// 	}
// 	return (arr);
// }

// int	main(int argc, char *argv[])
// {
// 	t_tavern	**starr;
// 	t_tavern	**scheck;
// 	int			n;

// 	handling_errors(argc, argv);
// 	starr = storing(argc, argv);
// 	n = sizeof(starr) / sizeof(starr[0]);
// 	scheck = bubble_sort(starr, n);
// 	if (scheck == starr)
// 		exit(0);
// 	else
// 		starr = scheck;
// 	feeding(starr);
// 	return (0);
// }

int main(int argc, char *argv[])
{
	handling_errors(argc, argv);
	// error_out();
	return (0);
}
