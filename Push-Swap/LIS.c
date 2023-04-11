/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:15 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/11 02:37:49 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	longestincrseb(t_tavern **sa, t_tavern **sb)
// {
// 	t_tavern	*tmp;
// 	t_tavern	*saver;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	j = 0;
// 	tmp = (*sa);
// 	while (1)
// 	{
// 		j = countlis(&tmp);
// 		if (i < j)
// 		{
// 			i = j;
// 			saver = tmp;
// 		}
// 		tmp = tmp->next;
// 		if (tmp == (*sa))
// 			break ;
// 	}
// 	countlis(&saver);
// 	stack_things(sa, sb);
// }

// int	countlis(t_tavern **sa)
// {
// 	int		i;
// 	t_tavern	*save;
// 	t_tavern	*keep;

// 	i = 0;
// 	save = (*sa);
// 	keep = save;
// 	while (1)
// 	{
// 		save->value = 0;
// 		if (keep->content <= save->content)
// 		{
// 			keep = save;
// 			keep->value = 1;
// 			i++;
// 		}
// 		save = save->next;
// 		if (save == (*sa))
// 			break ;
// 	}
// 	return (i);
// }

//*****************************************************************************

// void	stack_things(t_tavern **sa, t_tavern **sb)
// {
// 	int		size;
// 	int		max;

// 	max = longest_inc_sub(sa);
// 	size = ft_lstsize(*sa);
// 	printf("\033[36mmax = %d\033[0m\n", max);
// 	printf("\033[36msize = %d\033[0m\n", size);
// 	while (size > max)
// 	{
// 		if ((*sa)->value == 0)
// 		{
// 			push_to_b(sa, sb);
// 			size--;
// 		}
// 		else
// 			shift_up_stack_a(sa, 1);
// 	}
// }

// int	longest_inc_sub(t_tavern **head)
// {
// 	int			max_length;
// 	t_tavern	*final;

// 	max_length = assign_value(head, &final);
// 	// fake_swap(head, max_length);
// 	return (max_length);
// }

// void	fake_swap(t_tavern **head, int max)
// {
// 	int		i;

// 	swap_a(head, 0);
// 	i = longest_inc_sub(head);
// 	if (i > max)
// 	{
// 		write(1, "sa\n", 3);
// 		max = i;
// 		return ;
// 	}
// 	else
// 		swap_a(head, 0);

// }

void	assign_value(t_tavern **sa, t_tavern **sb, t_tavern *final)
{
	int			i;
	int			k;
	t_tavern	*best;
	t_tavern	*search;
	t_tavern	*longest;

	k = 0;
	longest = (*sa);
	final = *sa;
	while (sa)
	{
		longest = final;
		search = final->next;
		i = 0;
		while (search != final)
		{
			// printf("\033[1;33mThe longest S content : %d\033[0m\n", longest->content);
			// printf("\033[1;35mThe search F content : %d\033[0m\n", search->content);
			if (search->content > longest->content)
			{
				// printf("Enter\n");
				longest->value = 1;
				search->value = 1;
				// printf("\033[1;34mcontent %d -> longest value : %d\033[0m\n", longest->content, longest->value);
				// printf("\033[1;34mcontent %d -> search value : %d\0033[0m\n", search->content, search->value);
				longest = search;
				search = search->next;
				i++;
			}
			else
			{
				// printf("Enter2\n");
				search->value = 0;
				// printf("\033[1;34mcontent %d -> search value : %d\033[0m\n\n", search->content, search->value);
				search = search->next;
			}
		}
		if (k < i)
		{
			k = i;
			best = longest;
		}
		// printf("\n\033[1;31m-- next operation --\033[0m\n");
		final = final->next;
		if (final == (*sa))
			break ;
	}
	smallest_node(sa, 1);
	put_values(sa, &best);
	stack_things(sa, sb);
}


void	put_values(t_tavern **sa, t_tavern **best)
{
	t_tavern	*current;

	current = *sa;
	while ((*best)->content != (*sa)->content)
		shift_up_stack_a(best, 0);
	while (1)
	{
		if ((*best)->value != current->value)
			(*sa)->value = (*best)->value;
		// printf("content [%d] -> value [%d]\n", current->content, current->value);
		*best = (*best)->next;
		current = current->next;
		if (*best == *sa)
			break ;
	}
}
// int	assign_value(t_tavern **head, t_tavern **final)
// {
// 	int			i;
// 	int			k;
// 	t_tavern	*search;
// 	t_tavern	*longest;

// 	k = 0;
// 	longest = (*head);
// 	while (head)
// 	{
// 		// printf("hallo\n");
// 		search = longest;
// 		i = 0;
// 		while (1)
// 		{
// 			printf("\033[1;33mThe node content : %d\033[0m\n", longest->content);
// 			printf("\033[1;35mThe node content : %d\033[0m\n", search->content);
// 			if (search->content >= longest->content)
// 			{
// 				printf("Enter\n");
// 				search->value = 1;
// 				printf("\033[1;34mThe nodes value : %d\033[0m\n", search->value);
// 				longest = search;
// 				search = search->next;
// 				i++;
// 			}
// 			else
// 			{
// 				printf("Enter2\n");
// 				search->value = 0;
// 				printf("\033[1;34mThe nodes value : %d\033[0m\n", search->value);
// 				search = search->next;
// 			}
// 			if (search == (*head))
// 				break ;
// 		}
// 		if (k < i)
// 		{
// 			k = i;
// 			final = &search;
// 		}
// 		printf("\n\033[1;31m-- next operation --\033[0m\n");
// 		longest = longest->next;
// 		if (longest == (*head))
// 			break ;
// 	}
// 	// printf("%d\n", k);
// 	return (k);
// }

void	stack_things(t_tavern **sa, t_tavern **sb)
{
	int		size;

	size = ft_lstsize(*sa);
	while (size)
	{
		if ((*sa)->value == 0)
		{
			// printf("--------[%d]\n", (*sa)->content);
			push_to_stack(sa, sb, 1);
			size--;
			// printf("--------[%d]\n", (*sa)->content);
		}
		else
		{
			// printf("[%d]--------\n", (*sa)->content);
			shift_up_stack_a(sa, 1);
			// printf("[%d]--------\n", (*sa)->content);
			size--;
		}
	}
}

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

//***********************************************

// int main() {
//     // example linked list
//     t_tavern* head2 = NULL;
//     t_tavern* head = NULL;
//     t_tavern* second = NULL;
//     t_tavern* third = NULL;
//     t_tavern* fourth = NULL;
//     t_tavern* fifth = NULL;
//     t_tavern* sixth = NULL;
//     t_tavern* seventh = NULL;
//     t_tavern* eighth = NULL;
//     t_tavern* nineth = NULL;
//     t_tavern* tenth = NULL;

//     head = (t_tavern*) malloc(sizeof(t_tavern));
//     second = (t_tavern*) malloc(sizeof(t_tavern));
//     third = (t_tavern*) malloc(sizeof(t_tavern));
//     fourth = (t_tavern*) malloc(sizeof(t_tavern));
//     fifth = (t_tavern*) malloc(sizeof(t_tavern));
//     sixth = (t_tavern*) malloc(sizeof(t_tavern));
//     seventh = (t_tavern*) malloc(sizeof(t_tavern));
//     eighth = (t_tavern*) malloc(sizeof(t_tavern));
//     nineth = (t_tavern*) malloc(sizeof(t_tavern));
//     tenth = (t_tavern*) malloc(sizeof(t_tavern));

//     head->content = 7;
//     head->next = second;
// 	head->previous = tenth;
	
//     second->content = 3;
//     second->next = third;
// 	second->previous = head;

//     third->content = 8;
//     third->next = fourth;
// 	third->previous = second;

//     fourth->content = 9;
//     fourth->next = fifth;
// 	fourth->previous = third;

//     fifth->content = 0;
//     fifth->next = sixth;
// 	fifth->previous = fourth;

//     sixth->content = 4;
//     sixth->next = seventh;
// 	sixth->previous = fifth;

//     seventh->content = 6;
//     seventh->next = eighth;
// 	seventh->previous = sixth;

//     eighth->content = 1;
//     eighth->next = nineth;
// 	eighth->previous = seventh;

//     nineth->content = 2;
//     nineth->next = tenth;
// 	nineth->previous = eighth;

//     tenth->content = 10;
//     tenth->next = head;
// 	tenth->previous = nineth;

//     // printf("Linked List: ");
//     // printList(head);

//     // int lis_length = longest_inc_sub(&head);
//     int lis_length = assign_value(&head, &head2);
// 	// stack_things(&head, &head2);
//     // int lis_length2 = longestincrseb(&head);
//     printf("Longest increasing subsequence length: {%d}\n", lis_length);
//     // printf("Longest increasing subsequence length: --[%d]\n", lis_length2);

//     return 0;
// }

// write a function that compare a single node content with all other contents in the list, if the content of the other node is bigger than the content of the
// current node, assign to its value 1, and if its begger or equal to it assign to its value 0.
// after that swap the original list with sa, and again check the LIS, if the if the result of LIS after the sa is begger than the previous one, print sa and save the list.