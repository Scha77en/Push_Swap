/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:30 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/08 20:38:13 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node;
// 	t_list	*new_node;

// 	char	*s1 = ft_strdup("1");
// 	char	*s2 = ft_strdup("2");
// 	char	*s3 = ft_strdup("3");

// 	head = NULL;
// 	ft_lstadd_front(&head, ft_lstnew(s1));
// 	ft_lstadd_front(&head, ft_lstnew(s2));
// 	ft_lstadd_front(&head, ft_lstnew(s3));
// 	node = head;

// 	while (node)
// 	{
// 		printf("|result| %s\n", node -> content);
// 		node = node -> next;
// 	}
// }
