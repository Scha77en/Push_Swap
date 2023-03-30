/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:43:10 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/10 01:47:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int					*ptr;
	unsigned long long	m;

	m = (size * count);
	ptr = (int *)malloc(m);
	if (ptr)
		ft_bzero((char *)ptr, m);
	return (ptr);
}
