/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:56:55 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:59:35 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}

// int main()
// {
// 	int	s = 256;

// 	ft_memset(&s, 57, 1);
// 	printf("|RESULT| %d\n", s);
// }

// int	main(void)
// {
// 	int	src = 5;
// 	int dst[] ={256, 1 , 0};

// 	int *c = ft_memset(&dst, src, 1);
// 	printf("1st dst is: %d\n", c[2]);
// 	printf("2nd dst is: %d\n", *(int *)memset(&dst, src, 1));
// 	return (0);
// }
// int main()
// {
// 	int i = 255;
// 	int j = 257;
// 	ft_memset(&i, j, 2);
// 	printf("%d", i);
// }
