/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:03:10 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/23 03:53:40 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	str = (char *)haystack;
	if (needle[i] == '\0')
		return (str);
	while (i < n && str[i] != '\0')
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while ((i + j) < n && str[i + j] == needle[j] && str[i + j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
int main() {
	printf("%s", ft_strnstr(NULL, "hello", 0));
}
// int	main(void)
// {
// 	char	s1[] = "ich bi ein man";
// 	char	s2[0];
// 	char	s3[] = "bi";

// 	// printf("result 1: %s\n", strnstr(NULL, NULL, 0));
// 	// printf("result 2: %s\n", ft_strnstr(NULL, NULL, 0));
// 	return (0);
// }

/*
A locale consists of a number of categories for which country-dependent 
formatting or other specifications exist. 
A program's locale defines its code sets, 
date and time formatting conventions, monetary conventions, 
decimal formatting conventions, and collation (sort) order.
*/