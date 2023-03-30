/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:02:23 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:59:31 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//memcpy() is used to copy a block of memory from a location to another. 
// It is declared in string.h.
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (src == 0 && dst == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	src[100] = "wqer";
// 	char	dst[100] = "dfgdfg";

// 	ft_memcpy(dst, src, 10);
// 	printf("the new dst is : %s\n", dst);
// 	return (0);
// }

// (char*) - You are typecasting some data type to char-type pointer.

// int main(void)
// {
// 	char	str[] = "hello....";

// 	ft_memcpy(str+2, str, 10);
// 	printf("%s", str);
// }
