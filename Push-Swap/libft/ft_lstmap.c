/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:53 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/21 12:10:10 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

void d (void *c)
{
    free (c);
}

void *test(void *h)
{
    h = ft_strdup("0");
    return (h);
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	char	*s1 = ft_strdup("hello");
	char	*s2 = ft_strdup("wor\nld");
	char	*s3 = ft_strdup("hallo");

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(s1));
	ft_lstadd_back(&head, ft_lstnew(s2));
	ft_lstadd_back(&head, ft_lstnew(s3));
	node1 = head;
	node2 = malloc(sizeof(t_list) * sizeof(char *));
	node2 = node1;
	printf("|R| %s\n", node2 -> content);
	printf("|R| %s\n", node2 -> next -> content);
	// while (node1)
	// {
	// 	printf("|old| %s\n", node1->content + 2);
	// 	node1 = node1->next;
	// }

// 	node2 = ft_lstmap(head, &test, &d);

// 	while (node2)
// 	{
// 		printf("|new|%s\n",node2->content);
// 		node2 = node2->next;
// 	}
}
