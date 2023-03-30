/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:27:13 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/09 23:46:48 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main(void)
{
	char	str[] = "udhgkdjfhgu";
	int	str1[] = {365, 2, 3};

	printf("original before changing : %s\n", str);
	printf("my own befor changing : %s\n", str1);
	bzero(str, 1);
	printf("original : %s\n", str);
	ft_bzero(str1, 3 * sizeof(int));
	printf("my own : %d\n", str1[0]);
	printf("my own : %d\n", str1[1]);
	printf("my own : %d\n", str1[2]);
}
*/