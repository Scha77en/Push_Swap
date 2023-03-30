/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:20:12 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/05 01:01:24 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	char	str[20] = "Hello";

	// int	fd = open("file.txt",O_CREAT|O_RDWR);
	ft_putstr_fd(str, 1);
	return (0);
}
*/