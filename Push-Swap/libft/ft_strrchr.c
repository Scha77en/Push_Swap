/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:49:16 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/08 17:37:23 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while ((char)c != s[len])
	{
		if (len == 0)
			return (NULL);
		len--;
	}
	return ((char *)s + len);
}

/*int	main(void)
{
	const char	str[] = "Hello";
	const char	t = 0;

	printf("1 String after %c is %s\n", t, strrchr(str, t));
	printf("2 String after %c is %s", t, ft_strrchr(str, t));
	return (0);
}
*/
