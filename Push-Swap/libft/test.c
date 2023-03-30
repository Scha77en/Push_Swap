/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:49:34 by aouhbi            #+#    #+#             */
/*   Updated: 2022/10/16 08:23:54 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
/*
int	main(void)
{
	char	*str;
	char	*i;

	str = "Hello";
	i = ft_strlen(str);
	printf("string length is %lu", i);
	return (0);
}
*/
/*
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t len;
	
	len = ft_strlen(dst) + ft_strlen(src);
	if (len <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] != '\0' && i < dstsize - (len - ft_strlen(src)) - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	main(void)
{
	char	s1[] = "this is 1.";
	char	s2[] = "this is 2.";
	char	s3[] = "this is 3.";
	char	s4[] = "this is 4.";
	
	strlcat(s3, s4, 6);
	printf("the Final String : %s\n", s3);
	ft_strlcat(s1, s2, 6);
	printf("the Final String : %s\n", s1);
	return (0);
}
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
  
int main(){
    FILE* fp;
    fp = fopen("test.txt","r");
    
    if(fp==NULL){          //Error handling in case if the file doesn't exists 
        perror("Message from perror "); 
        //User-Defined message passed as an argument string in perror() function
        return -1;
    }
    fclose(fp);
    return 0;
}
