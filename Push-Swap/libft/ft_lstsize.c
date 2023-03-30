/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:04:24 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:59:50 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int main(void)
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
// 	node2 = head;
// 	node1 = ft_lstlast(head);
// 	printf("|LAST| %s\n", node1 -> content);
// 	while (node2)
// 	{
// 		printf("|RESULT| %s\n", node2 -> content);
// 		node2 = node2 -> next;
// 	}
// 	printf("|SIZE| %d", ft_lstsize(head));
// }
