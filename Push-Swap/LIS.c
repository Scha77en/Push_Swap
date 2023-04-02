/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:15 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/02 22:56:52 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	longest_inc_sub(t_tavern **head)
{
	int			max_length;
	t_tavern	*final;

	max_length = assign_value(head, &final);
	return (max_length);
}

int	assign_value(t_tavern **head, t_tavern **final)
{
	int			i;
	int			k;
	t_tavern	*search;
	t_tavern	*longest;

	k = 0;
	longest = (*head);
	while (head)
	{
		// printf("hallo\n");
		search = longest;
		i = 0;
		while (1)
		{
			printf("\033[1;33mThe node content : %d\033[0m\n", longest->content);
			printf("\033[1;35mThe node content : %d\033[0m\n", search->content);
			if (search->content >= longest->content)
			{
				printf("Enter\n");
				search->value = 1;
				printf("\033[1;34mThe nodes value : %d\033[0m\n", search->value);
				search = search->next;
				i++;
			}
			else if (search->content < longest->content)
			{
				printf("Enter2\n");
				search->value = 0;
				printf("\033[1;34mThe nodes value : %d\033[0m\n", search->value);
				search = search->next;
			}
			if (search == longest)
				break ;
		}
		if (k < i)
		{
			k = i;
			final = &search;
		}
		printf("\n\033[1;31m-- next operation --\033[0m\n");
		longest = longest->next;
		if (longest == (*head))
			break ;
	}
	// printf("%d\n", k);
	return (k);
}

// void	stack_things(t_tavern **sa, t_tavern **sb)
// {
// 	int		i;

// 	i = 0;
// 	while (i < ft_lstsize(*sa))
// 	{
// 		if (sa -> value == 0)
// 		{
// 			push_to_b(&sa,&sb);
// 			i++;
// 		}
// 		else
// 			shift_up_stack_a(&sa, 1);
// 	}
	
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// int lengthOfLIS(t_tavern* head)
// {
//     int length = 0;
//     int max_length = 0;
//     int prev_value = -1;
//     t_tavern* current = head;
//     while (current != NULL) {
//         if (current->content > prev_value) {
//             length++;
//             if (length > max_length) {
//                 max_length = length;
//             }
//         } else {
//             length = 1;
//         }
//         prev_value = current->content;
//         current = current->next;
// 		if (current == head)
// 			break ;
//     }
//     return max_length;
// }

//**********************************************************************************************************************

int	longestincrseb(t_tavern **heada)
{
	t_tavern	*tmp;
	t_tavern	*saver;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = (*heada);
	while (1)
	{
		j = countlis(&tmp);
		if (i < j)
		{
			i = j;
			saver = tmp;
		}
		tmp = tmp->next;
		if (tmp == (*heada))
			break ;
	}
	countlis(&saver);
	return (i);
}

int	countlis(t_tavern **heada)
{
	int		i;
	t_tavern	*save;
	t_tavern	*keep;

	i = 0;
	save = (*heada);
	keep = save;
	while (1)
	{
		save->value = 0;
		if (keep->content <= save->content)
		{
			keep = save;
			keep->value = 1;
			i++;
		}
		save = save->next;
		if (save == (*heada))
			break ;
	}
	return (i);
}

// int	fakeswap(t_tavern **heada, int *lis)
// {
// 	int		new;

// 	sa_swap_a(heada, 0);
// 	new = longestincrseb(heada);
// 	if (new > *lis)
// 		return (write(1, "sa\n", 3), *lis = new, 1);
// 	else
// 		return (sa_swap_a(heada, 0), longestincrseb(heada), 0);
// }

// void	ft_push0tob(t_tavern **heada, t_tavern **headb)
// {
// 	int		pushing;
// 	int		i;

// 	i = ft_lstsize(*heada);
// 	pushing = longestincrseb(heada);
// 	while (i > pushing)
// 	{
// 		if (fakeswap(heada, &pushing))
// 			continue ;
// 		if (!(*heada)->key)
// 		{
// 			pb_push_b(heada, headb, 1);
// 			i--;
// 		}
// 		else
// 			ra_rotate_a(heada, 1);
// 	}
// }

// void printList(struct Node* head) {
//     struct Node* current = head;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

int main() {
    // example linked list
    t_tavern* head2 = NULL;
    t_tavern* head = NULL;
    t_tavern* second = NULL;
    t_tavern* third = NULL;
    t_tavern* fourth = NULL;
    t_tavern* fifth = NULL;

    head = (t_tavern*) malloc(sizeof(t_tavern));
    second = (t_tavern*) malloc(sizeof(t_tavern));
    third = (t_tavern*) malloc(sizeof(t_tavern));
    fourth = (t_tavern*) malloc(sizeof(t_tavern));
    fifth = (t_tavern*) malloc(sizeof(t_tavern));

    head->content = 3;
    head->next = second;

    second->content = 4;
    second->next = third;

    third->content = 5;
    third->next = fourth;

    fourth->content = 1;
    fourth->next = fifth;

    fifth->content = 6;
    fifth->next = head;

    // printf("Linked List: ");
    // printList(head);

    int lis_length = longest_inc_sub(&head);
    int lis_length2 = longestincrseb(&head);
    printf("Longest increasing subsequence length: {%d}\n", lis_length);
    printf("Longest increasing subsequence length: --[%d]\n", lis_length2);

    return 0;
}

// write a function that compare a single node content with all other contents in the list, if the content of the other node is bigger than the content of the
// current node, assign to its value 1, and if its begger or equal to it assign to its value 0.
// after that swap the original list with sa, and again check the LIS, if the if the result of LIS after the sa is begger than the previous one, print sa and save the list.