/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:33:35 by aouhbi            #+#    #+#             */
/*   Updated: 2022/10/19 22:54:44 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 000 && c <= 0177)
		return (1);
	return (0);
}

/*int	main(void)
{
	char	x;

	x = '{';
	printf("the result is %d", ft_isascii(x));
	return (0);
}
*/