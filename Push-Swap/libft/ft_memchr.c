/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:21:17 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:59:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const char	*sc;

	i = -1;
	sc = (const char *)s;
	while (++i < n)
		if (*(sc + i) == (char)c)
			return ((void *)sc + i);
	return (NULL);
}
*/
// int	main(void)
// {
// 	char	str[] = "H0lo";
// 	char	t = 'l';

// 	// printf("searching for: %c\nfound: %s\n", t, memchr(NULL, 0, 1));
// 	printf("searching for: %c\nfound: %s\n", t, ft_memchr(NULL, 0, 1));
// }

// int main(void)
// {
// 	int	str[] = {1, 5, 98, 8};
// 	int	t = 98;

// 	printf("%s", memchr(str, 'b', 20));
// }
