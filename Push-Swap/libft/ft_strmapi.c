/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:00:35 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/10 19:26:35 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	if (!s || !f)
		return (0);
	i = 0;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// char	f(unsigned int i, char c)
// {
// 	if (i == 0)
// 		c = 'K';
// 	if (i == 4)
// 		c = 'O';
// 	printf("the index is: %d, and the value is: %c\n", i, c);
// 	return (c);
// }

// int main(void)
// {
// 	char	str[] = "halo.";

// 	ft_strmapi(str, f);
// }
