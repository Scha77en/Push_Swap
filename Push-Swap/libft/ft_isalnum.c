/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:48:57 by aouhbi            #+#    #+#             */
/*   Updated: 2022/10/15 23:49:00 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	unsigned char	x;

	x = '4';
	printf("the result is %d", ft_isalnum(x));
	printf("isalpha is %d", ft_isalpha(x));
	return (0);
}
*/