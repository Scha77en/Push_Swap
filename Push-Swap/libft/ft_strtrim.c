/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 05:04:48 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/10 05:01:22 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_s_start(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

int	ft_s_end(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == NULL)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_s_start(s1, set);
	end = ft_s_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	ptr = (char *)malloc(end - start + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, end - start + 1);
	return (ptr);
}

// int	main(void)
// {
// 	char	str[] = "*--/Ha*lo-/";
// 	char	c[] = "*-/";

// 	printf("result: %s", ft_strtrim("", ""));
// }
