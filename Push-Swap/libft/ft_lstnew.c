/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:04:13 by aouhbi            #+#    #+#             */
/*   Updated: 2022/11/11 04:59:46 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node1;

	node1 = (t_list *)malloc(sizeof(t_list));
	if (!node1)
		return (0);
	node1 -> content = content;
	node1 -> next = NULL;
	return (node1);
}

// int	main(void)
// {
// 	t_list	*node;
// 	char s[] = "abc";

// 	node = ft_lstnew(s);
// 	printf("%p", node -> content);
// }

/*
t_list *ft_lstnew(void *content)
{
	t_list *new; // a variable where to store the data

	if(!(new = (t_list *)malloc(sizeof(t_list))))
		return (0);

	node1 -> content = content;
	node1 -> next = NULL;
	return (new);
}
*/