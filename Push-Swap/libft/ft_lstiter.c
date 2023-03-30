/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:39 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/12 23:14:58 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f(void *c)
// {
// 	c = ft_strdup("0");
// 	printf("the value is: %s\n", c);
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
// 	ft_lstadd_back(&head, ft_lstnew(s3));
// 	ft_lstadd_back(&head, ft_lstnew(s2));
// 	ft_lstadd_back(&head, ft_lstnew(s1));
// 	node1 = head;
// 	while (node1)
// 	{
// 		printf("|old| %s\n", node1->content);
// 		node1 = node1->next;
// 	}
// 	node2 = head;
// 	ft_lstiter(node2, f);
	// while (node2)
	// {
	// 	printf("|new|%s\n", node2 -> content);
	// 	node2 = node2->next;
	// }
// }
