/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:26 by aouhbi            #+#    #+#             */
/*   Updated: 2023/03/30 01:20:04 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lnode;

	if (!new)
		return ;
	while (!*lst)
	{
		*lst = new;
		return ;
	}
	lnode = ft_lstlast(*lst);
	lnode -> next = new;
}
/*
int	main(void)
{
	t_list *mylist = (t_list *)malloc(sizeof(t_list));
	mylist->next = NULL;
	char	content[] = "CONTENT.";
	mylist->content = content;
	t_list *node1 = ft_lstnew((void *)content);
	char	content2[] = "CONTENT2.";
	t_list *node2 = ft_lstnew((void *)content2);
	ft_lstadd_front(&mylist, node1);
	ft_lstadd_front(&mylist, node2);
	printf("the result is: %s\n", (char *)mylist->content);
	return (0);
}
*/