/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:08:50 by aouhbi            #+#    #+#             */
/*   Updated: 2023/03/30 04:47:16 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_d(t_tavern **lst, t_tavern *new)
{
	t_tavern	*lnode;

	if (!new)
		return ;
	while (!(*lst))
	{
		*lst = new;
		return ;
	}
	lnode = ft_lstlast(*(lst));
	lnode -> next = new;
	new -> previous = lnode;
}

t_tavern	*ft_lstnew_d(int content)
{
	t_tavern	*node1;

	node1 = (t_tavern *)malloc(sizeof(t_tavern));
	if (!node1)
		return (NULL);
	node1 -> content = content;
	node1 -> next = NULL;
	node1 -> previous = NULL;
	return (node1);
}

t_tavern	*ft_lstlast(t_tavern *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static int	nb_c(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static int	strlenword(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **strs, int j)
{
	while (j--)
		free(strs[j]);
	free(strs);
	return ;
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (0x0);
	i = 0;
	j = -1;
	str = (char **)malloc((nb_c(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < nb_c(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, strlenword(s, c, i));
		if (!str[j])
		{
			ft_free(str, j + 1);
			return (0);
		}
		i += strlenword(s, c, i);
	}
	str[j] = 0;
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (src == 0 && dst == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
