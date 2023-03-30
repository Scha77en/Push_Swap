/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:55:15 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:53:55 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		n--;
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	int	array1[] = {11, 22, 33, 44, 55};
// 	int	array2[] = {11, 22, 35, 44, 55};

// 	printf("result 1: %d\n", ft_memcmp(array1, array2, 8));
// 	// printf("result 2: %d\n", ft_memcmp(array2, array1, 9));
// 	// printf("result 3: %d\n", ft_memcmp(array1, array2, 3));
// 	return (0);
// }

// int main(void)
// 	{
// 	    char    array1[] = "hello";
// 	    char    array2[] = "helzo";

// 	    printf("result 1: %d\n", memcmp(array1, array2, 5));
// 	    printf("result 2: %d\n", ft_memcmp(array2, array1, 5));
// 	    printf("result 3: %d\n", ft_memcmp(array1, array2, 2));
// 	    return (0);
// }