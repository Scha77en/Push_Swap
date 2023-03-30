/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:22:22 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/23 01:22:33 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if ((dst == NULL && src == NULL) || dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + srclen);
	while (src[i] != '\0' && dstlen < dstsize - 1)
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (dstlen + ft_strlen(&src[i]));
}

/*
int main(void)
{
	char	s[] = "sukablyat";
	char	s1[] = "sukablyat";
	char	d[10];
	char	d1[10];

	strlcat(d, s, 5);
	printf("My own : %s\n", s);
	printf("original : %s\n", d);
	strlcpy(d1, s1, 5);
	printf("My own : %s\n", s1);
	printf("My own : %s\n", d1);
	
	return (0);
}
*/
/*
int	main(void)
{
	char	s1[] = "";
	char	s2[] = "";
	char	s3[] = "";
	char	s4[] = "yoo";

	strlcat(NULL, s2, 0);
	printf("1 the Final String : %s\n", s1);
	ft_strlcat(NULL, s4, 0);
	printf("2 the Final String : %s\n", s3);
	return (0);
}
*/

// int main()
// {
// 	char s[] = "Hello";
// 	printf("%lu", ft_strlcat(NULL, "hello", 1));
// }
