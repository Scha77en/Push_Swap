/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:28:53 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/06 01:11:05 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//	s - This is the C string to be scanned.
//	c - This is the character to be searched in s.
//  **	The functions strchr() and strrchr() return a pointer
//	*	to the located character,
//	*	or NULL if the character does
//  *	not appear in the string.
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((char)c == *s)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
/*
int	main(void)
{
	const char	str[] = "Hello";
	const char	t = 'l';

	printf("searching for: %c\nresult: %s\n", t, ft_strchr(str, t));
	return (0);
}*/

// c char is translated to an ASCII int value.
// *s is pointing to the first element in its array.

// L-28 return ((char *)s) returned the 
// value(e) that is pointed(*) in the string s.
/*char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}
*/