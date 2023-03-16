/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:15 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/08 19:03:41 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search(t_tavern *head, int value)
{
	int			l;
	int			r;
	t_tavern	*curr;
	int			i;
	int			mid;

	l = 0;
	r = 0;
	i = -1;
	curr = head;
	while (curr)
	{
		r++;
		curr = curr->next;
	}
	while (l < r)
	{
		mid = l + (r - l) / 2;
		curr = head;
		while (++i < mid)
			curr = curr -> next;
		if (curr -> content < value)
		{
			l = mid + 1;
		}
		else
			r = mid;
	}
	return (l);
}

int lis(int *arr, int n)
{
	t_tavern	*head;
	t_tavern	*curr;
	int			index;
	int			j;
	int			i;

	i = -1;
	j = -1;
	head = new_node(arr[0]);
	while (++i < n)
	{
		if (arr[i] > head->content)
		{
			t_tavern *node = new_node(arr[i]);
			node->next = head;
            head = node;
        }
		else
		{
			index = search(head, arr[i]);
			curr = head;
			while (++j < index - 1)
				curr = curr->next;
            t_tavern *node = new_node(arr[i]);
            node->next = curr->next;
            curr->next = node;
        }
    }
    int count = 0;
    t_tavern *curr = head;
    while (curr)
	{
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = lis(arr, n);
    printf("Length of Longest Increasing Subsequence is %d\n", result);
    return 0;
}