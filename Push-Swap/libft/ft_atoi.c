/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:49:22 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 05:01:24 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ishara;
	int	res;

	i = 0;
	ishara = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ishara *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (ishara * res);
}

// int	main(void)
// {
// 	char	s[] = "2147483647";

// 	printf("The result is: %d", atoi(s));
// 	return (0);
// }
/*
#include <stdio.h>
//The atoi function skips all white-space characters at thebeginning of the string,
//white-space characters: Space'32', tab'9', 
line feed'10' (newline),
//carriage return'13', form feed'12', and vertical tab'11'. 
'-' = 45 (Hyphen), '+' = 43 (Plus). 







// Initialize index of first digit, what we are currently pointing to
// Initialize l ishira as positive
 // Initialize result


 // -1234: 0 * 10 + (49 - 48) = 1
 // 1 * 10 + (50-48) = 10 + 2 = 12 ...

*/
