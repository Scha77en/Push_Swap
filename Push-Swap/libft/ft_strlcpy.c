/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 05:07:22 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 02:25:56 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
/*
int	main(void)
{
	char	srcc[] = "abdou";
	char	dsst[20] = "..........";

	printf("|BEFORE|:\n src: %s\ndst: %s\n", srcc, dsst);
	strlcpy(dsst, srcc, 10);
	printf("|AFTER|:\n src: %s\ndst: %s\n", srcc, dsst);
	return (0);
}
*/