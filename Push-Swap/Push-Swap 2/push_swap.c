/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:48:37 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/12 21:31:13 by aouhbi           ###   ########.fr       */
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

	// printf("[%d]\n", argc);
	i = 0;
	while (argv[++i])
		analyse_arg(argv[i]);
	i = 0;
	while (++i < argc)
	{
		// printf("(%s)\n", argv[i]);
		j = -1;
		len = ft_split(argv[i], ' ');
		while (len[++j])
		{
			// printf("-%s-\n", len[j]);
			check_length(len[j]);
			tmp = ft_lstnew_d(ft_atoi(len[j]));
			ft_lstadd_back_d(sa, tmp, 1);
			// printf("[%p]\n", tmp->previous);
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
			// printf("[[[%p]]\n", tmp->previous);
			if (tmp2->content == tmp -> content)
				error_out();
		}
		tmp = tmp2;
		while (tmp -> next)
		{
			tmp = tmp -> next;
			// printf("[[%p]]]\n", tmp->next);
			if (tmp2->content == tmp -> content)
				error_out();
		}
		// printf("/%d/\n", tmp2->content);
		tmp2 = tmp2->next;
		// if (!tmp2)
		// 	break ;
		// printf("here\n");
	}
	tmp = NULL;
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
			if (str[i - 1] != ' ' && str[i - 1] != '\0')
				trigger = 3;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				error_out();
		}
		// if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == ' '
		// 		|| str[i + 1] == '\0' || str[i + 1 == '-'
		// 			&& str[i + 1] == '+']))
		// printf("|||%ld|||\n", trigger);
		// printf("|%c|\n", str[i]);
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
	// printf("string = %s\n", s);
	while (s[++j])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		// printf("character = %c\n", s[j]);
	}
	// printf("length = %d\n", i);
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

// int	main(int argc, char *argv[])
// {
// 	t_tavern	*sa;
// 	t_tavern	*sb;
// 	t_tavern	*final;

// 	sa = NULL;
// 	final = NULL;
// 	handling_errors(argc, argv, &sa);
// 	ft_lstadd_back_d(&sa, NULL, 0);
	
// 	return (0);
// }

// Longest increasing subsecuance ending function.

// whene finding the LIS give to each number of it number 1, other numbers gets 0.

// make the list circular, and add one more member to the struct to give the LIS 1. 0 by default.

// make a fake swap function, what will she do ? this function swaps the list and tries to implement the LIS function to see if it can find 
// bigger LIS in the list after swaping.