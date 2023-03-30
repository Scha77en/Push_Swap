/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:37 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/12 22:55:56 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

// void	d(void *c)
// {
// 	free(c);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*delnode;
// 	int		i;

// 	char	*s1 = ft_strdup("1");
// 	char	*s2 = ft_strdup("2");
// 	char	*s3 = ft_strdup("3");

// 	head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew(s1));
// 	ft_lstadd_back(&head, ft_lstnew(s2));
// 	ft_lstadd_back(&head, ft_lstnew(s3));
// 	node1 = head;
// 	i = 0;
// 	while (node1)
// 	{
// 		printf("|RESULT| %s\n", node1 -> content);
// 		if (i == 1)
// 			ft_lstdelone(node1, d);
// 		node1 = node1 -> next;
// 		i++;
// 	}
// 	while (head)
// 	{
// 		printf("|RESULT| %s\n", head -> content);
// 		head = head -> next;
// 	}
// }
