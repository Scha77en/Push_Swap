/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:03:49 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/09 23:04:08 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int    main(void)
// {
// 	t_list *mylist = (t_list *)malloc(sizeof(t_list));
// 	mylist->next = 0;
// 	char add[] = "lastone.";
// 	mylist->content = add;
// 	char    content[] = "CONTENT.";
// 	t_list *node1 = ft_lstnew((void *)content);
// 	char    content2[] = "CONTENT2.";
// 	t_list *node2 = ft_lstnew((void *)content2);
// 	ft_lstadd_front(&mylist, node1);
// 	ft_lstadd_front(&mylist, node2);
// 	printf("the result is: %s\n", ft_lstlast(mylist));
// 	return (0);
// }
