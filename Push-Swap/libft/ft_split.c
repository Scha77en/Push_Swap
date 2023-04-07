/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:59:56 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/06 21:25:13 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Return value: The array of new strings resulting from the split.
//External functs: malloc, free.
/*
Description:
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.

NULL if the allocation fails.
*/

#include "libft.h"

static int	rows_num(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*get_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_mem(char **ptr, int j)
{
	while (j >= 0)
	{
		free(ptr[j]);
		j--;
	}
	free(ptr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	g_end;
	size_t	j;
	int		g_start;
	char	**ptr;

	ptr = malloc((rows_num(s, c) + 1) * sizeof(char *));
	if (!s || !ptr)
		return (0);
	g_end = -1;
	j = 0;
	g_start = -1;
	while (++g_end <= ft_strlen(s))
	{
		if (s[g_end] != c && g_start < 0)
			g_start = g_end;
		else if ((s[g_end] == c || g_end == ft_strlen(s)) && g_start >= 0)
		{
			ptr[j++] = get_word(s, g_start, g_end);
			if (!ptr[j - 1])
				return (free_mem(ptr, (j - 1)), NULL);
			g_start = -1;
		}
	}
	return (ptr[j] = 0, ptr);
}

int	main(void)
{
	char	str[] = "MON TUE WENS ";
	char	**result = ft_split(str, ' ');

	printf("|R| %s\n", *result);
	printf("|R| %s\n", result[0]);
	printf("|R| %s\n", result[1]);
	printf("|R| %s\n", result[2]);
	printf("|R| %c\n", result[2][1]);
	printf("|R| %s\n", result[3]);
}

// int main()
// {
// 	char **ptr = ft_split("jkdfh laksdfj odisf lk ", ' ');
// 	while ("amine");
// }
/*
int	main()
{
char str[20] = "This is string.";
char **result = ft_split(str, 'r');
printf("The result is %s\n", *result);
printf("The result is %s\n", result[0]);
printf("The result is %s\n", result[1]);
return 0;
}
*/
// #include "libft.h"

// char	get_token(char const *s, char c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = ft_strdup(s);
// 	while (str[i])
// 		{
// 			if (ft_strchr(str, c) == c || ft_strchr(str, c) == 0)
// 				break ;
// 			i++;
// 		}
// 	str[i] == '\0';
// 	return (str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		*i;
// 	const char	*ptr;
// 	const char	token;

// 	i = ft_strlen(token) + 1;
// 	token = get_token(s, c);
// 	ptr = (char *)malloc(sizeof(char * i));
// 	if (!ptr)
// 		return (NULL);
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// int	main(void)
// {
// 	char	sstr[30] = "MON TUE WENS ";
// 	char	**result = ft_split(sstr, ' ');

// 	printf("|RESULT| %s\n", result[0]);
// 	printf("|RESULT| %s\n", result[1]);
// 	printf("|RESULT| %s\n", result[2]);
// 	printf("|RESULT| %s\n", result[3]);
// 	return (0);
// }

/*
char str[] == "MON TUE WINS THUR FRI SAT SUN";

char delimiter[] = ' '; // space.

the result should be like that:

MON
TUE
WINS
THUR
FRI
SAT
SUN
*/
/*
you will duplicate the string given by using
 ft_strdup. in the duplicated string
you will need to search for the delimiter, 
and when you find it you will copy that
lenght of the string to the allocated memory 
u allocated using malloc, leave a space
for the NULL at the end, put the NULL and 
continue to find the next delimiter untile
you reach NULL at the end of the string, normally 
each time you reach the delimiter
you will have to duplicate to the allocated memory and r
eturn the allocated memory string
but you cant return many times in a funtion or program because 
the funtion or the program
will exit immediatly at the return. so that means to return all 
the strings that will be writing
in the main section of the program using a loop.
*/