/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:31:52 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 23:49:50 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lnode;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lnode = ft_lstlast(*lst);
	lnode -> next = new;
}

t_list	*ft_lstnew(char *content, ssize_t readed)
{
	t_list	*node1;
	int		i;

	if (readed == 0 || !content)
		return (NULL);
	node1 = (t_list *)malloc(sizeof(t_list));
	if (!node1)
		return (free(content), free(node1), NULL);
	node1 -> next = NULL;
	node1->content = malloc(readed + 1);
	if (!node1->content)
		return (NULL);
	i = -1;
	while (content[++i] && i < readed)
		node1->content[i] = content[i];
	node1->content[i] = '\0';
	return (node1);
}

int	ft_lstchr(t_list *head, char *s, int v)
{
	int		i;
	t_list	*current;

	if (v == 0)
	{
		while (s[v])
			v++;
		return (v);
	}
	if (!head)
		return (0);
	current = ft_lstlast(head);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*allocate_to_line(t_list *head)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (head)
	{
		i = 0;
		while (head->content[i])
		{
			if (head->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		head = head->next;
	}
	line = malloc(len + 1);
	if (!line)
		return (free(line), NULL);
	return (line);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*node;
	t_list	*n_node;

	if (!lst)
		return ;
	node = lst;
	while (node)
	{
		free(node->content);
		n_node = node->next;
		free (node);
		node = n_node;
	}
}
