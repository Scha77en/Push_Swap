/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:55:25 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:58:51 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	ptr = (char *)malloc(slen);
	if (!ptr || !s1)
		return (0);
	ft_memcpy(ptr, s1, (size_t)slen);
	return (ptr);
}
