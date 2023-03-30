/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:34 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/09 23:04:02 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst && *del)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
	*lst = 0;
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

// 	char	*s1 = ft_strdup("1");
// 	char	*s2 = ft_strdup("2");
// 	char	*s3 = ft_strdup("3");

// 	head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew(s1));
// 	ft_lstadd_back(&head, ft_lstnew(s2));
// 	ft_lstadd_back(&head, ft_lstnew(s3));
// 	node1 = head;
// 	while (node1)
// 	{
// 		printf("|RESULT| %s\n", node1 -> content);
// 		node1 = node1 -> next;
// 	}
// 	ft_lstclear (&head, d);
// 	node2 = head;
// 	while (node2)
// 	{
// 		printf("|RESULT| %s\n", node2 -> content);
// 		node2 = node2 -> next;
// 	}
// 	if (!node2)
// 		printf("ALL CLEARED.");
// }