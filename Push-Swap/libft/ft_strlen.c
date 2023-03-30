/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:10:19 by aouhbi            #+#    #+#             */
/*   Updated: 2023/03/30 03:40:48 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
//size_t aka 'unsigned long' -- size_t type is a base unsigned integer type. 
//format specifier: %lu/%zu
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char	*str;

	str = "Hello";
	printf("string length is %lu", ft_strlen(str));
	return (0);
}
*/
//	*str takes value from address of str.