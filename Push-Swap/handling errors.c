/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:57:29 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/14 20:15:32 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	handling_errors(int argc, char *argv[])
// {
	
// }

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void    check_arg(char *s)
{
    int    i;
    int    var;

    i = 0;
    var = 0;
    while (s[i])
    {
        if ((s[i] < '0' || s[i] > '9')
            && (s[i] != ' ' && s[i] != '-' && s[i] != '+'))
            ft_error();
        if ((s[i] >= '0' && s[i] <= '9')
            || (s[i] == ' ' || s[i] == '-' || s[i] == '+'))
            if ((s[i] == '-' || s[i] == '+'))
                var++;
        if ((s[i] == '-' || s[i] == '+') && (s[i + 1] == '\0'
                || s[i + 1] == ' '))
            var++;
        i++;
    }
    if (var > 1)
			ft_error();
}

int main(void)
{
	check_arg(char *s);
	return (0);
}