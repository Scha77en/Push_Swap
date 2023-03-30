/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:41:25 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:59:39 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	The memmove() function copies len bytes from string src to string dst.
//  The two strings may overlap; the copy is always done in a 
//non-destructive manner.
/*	memmove take the data from the source to a buffer, 
and then moves that data from the buffer 
to the distination*/
/*	C uses a buffer to output or input variables.
The buffer stores the variable that is */
/*supposed to be taken in (input) or sent 
out (output) of the program. A buffer needs 
to be cleared before the next input is taken in.*/

/*with memmove we can copy a source of block of memory to a destination
block of memory even when those blocks of memory overlap, whereas 
with memcpy the behavior would be undefined */
//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*srcc;
	char	*dest;

	i = -1;
	srcc = (char *)src;
	dest = (char *)dst;
	if (dest < srcc)
	{
		while (++i < len)
			dest[i] = srcc[i];
	}
	else if (dest > srcc)
	{
		while (len > 0)
		{
			dest[len -1] = srcc[len -1];
			len--;
		}
	}
	if (dest == 0 || srcc == 0)
		return (0);
	return (dest);
}
//typecasting values to a data type char-type pointer.

// int	main(void)
// {
// 	int	src = 1337;
// 	int dst = 1;

// 	printf("1st dst is: %d\n", *(int *)ft_memmove(&dst, &src, 2));
// 	// printf("2nd dst is: %d\n", *(int *)memmove(&dst, &src, 2));
// 	return (0);
// }
// int main()
// {
// 	int array1[] = {1, 2, 3};
// 	int array2[] = {0, 0, 0};

// 	printf("|RESULT| %d\n", (int)ft_memmove(array2, array1, 2));
// }
