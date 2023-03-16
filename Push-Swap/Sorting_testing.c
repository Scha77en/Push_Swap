/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting_testing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:48:07 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/10 19:55:41 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_tavern *a, t_tavern *b)
{
	int	temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

char	*bubble_sort(t_tavern *head)
{
	int			swapped;
	t_tavern	*ptr1;
	t_tavern	*lptr;

	lptr = NULL;
	if (head == NULL)
		return ;
	swapped = 0;
	while (swapped)
	{
		swapped = 0;
		ptr1 = head;
		while (ptr1 -> next != lptr)
		{
			if (ptr1 -> content > ptr1 -> next -> content)
			{
				swap_nodes(ptr1, ptr1 -> next);
				swapped = 1;
			}
			ptr1 = ptr1 -> next;
		}
		lptr = ptr1;
	}
}

// void push(Node **head_ref, int new_data) {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->data = new_data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }

// char	*bubble_sort(t_list *head)
// {
// 	int		i;
// 	int		j;
// 	char	*temp;
// 	char	*sorted;

// 	sorted = arr;
// 	i = -1;
// 	while (++i < n - 1)
// 	{
// 		j = -1;
// 		while (++j < n - i - 1)
// 		{
// 			if (arr[j] > arr[j + 1])
// 			{
// 				temp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = temp;
// 			}
// 		}
// 	}
// 	return (arr);
// }

// int main()
// {
//     char arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr)/sizeof(arr[0]);
// 	printf("%d\n", n);
//     printf("Original array: ");
//     for (int i=0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
//     bubble_sort(arr, n);
//     printf("Sorted array: ");
//     for (int i=0; i < n; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }
