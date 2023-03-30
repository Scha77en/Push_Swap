/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:00:14 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 05:02:36 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			f(i, s);
			i++;
			s++;
		}
	}
}

// void	f(unsigned int i, char *c)
// {
// 	if (i == 2)
// 		*c = 'k';
// }

// int	main(void)
// {
// 	char	str[] = "hello.";

// 	ft_striteri(str, f);
// 	printf("|NEW| %s", str);
// 	return (0);
// }
