/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting_testing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:48:07 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/08 06:43:08 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_linked_list(t_tavern **head)
{
	t_tavern	*current;
	t_tavern	*next;

	if (*head == NULL)
		return ;
	current = *head;
	while (1)
	{
		next = current->next;
		while (next != *head)
		{
			if (current->content > next->content)
			{
				swap_nodes(&current);
				next = next->next;
			}
			current = current->next;
			if (current == *head)
				break ;
		}
	}
}

void	swap_nodes(t_tavern **head)
{
	t_tavern	*temp;
	t_tavern	*curr;

	temp = *head;
	curr = *head;
	*head = (*head)->next;
	curr->next = *head;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

int main() {
    // example linked list
    t_tavern* tmp = NULL;
    t_tavern* head = NULL;
    t_tavern* head2 = NULL;
    t_tavern* second = NULL;
    t_tavern* third = NULL;
    t_tavern* fourth = NULL;
    t_tavern* fifth = NULL;
    t_tavern* sixth = NULL;
    t_tavern* seventh = NULL;
    t_tavern* eighth = NULL;
    t_tavern* nineth = NULL;
    t_tavern* tenth = NULL;

    head = (t_tavern*) malloc(sizeof(t_tavern));
    second = (t_tavern*) malloc(sizeof(t_tavern));
    third = (t_tavern*) malloc(sizeof(t_tavern));
    fourth = (t_tavern*) malloc(sizeof(t_tavern));
    fifth = (t_tavern*) malloc(sizeof(t_tavern));
    sixth = (t_tavern*) malloc(sizeof(t_tavern));
    seventh = (t_tavern*) malloc(sizeof(t_tavern));
    eighth = (t_tavern*) malloc(sizeof(t_tavern));
    nineth = (t_tavern*) malloc(sizeof(t_tavern));
    tenth = (t_tavern*) malloc(sizeof(t_tavern));

    head->content = 40;
    head->next = second;
	head->previous = tenth;
	
    second->content = 50;
    second->next = third;
	second->previous = head;

    third->content = 80;
    third->next = fourth;
	third->previous = second;

    fourth->content = 60;
    fourth->next = fifth;
	fourth->previous = third;

    fifth->content = 30;
    fifth->next = sixth;
	fifth->previous = fourth;

    sixth->content = 90;
    sixth->next = seventh;
	sixth->previous = fifth;

    seventh->content = 100;
    seventh->next = eighth;
	seventh->previous = sixth;

    eighth->content = 70;
    eighth->next = nineth;
	eighth->previous = seventh;

    nineth->content = 10;
    nineth->next = tenth;
	nineth->previous = eighth;

    tenth->content = 20;
    tenth->next = head;
	tenth->previous = nineth;

	sort_linked_list(&head);
	printf("out\n");
	tmp = head;
	while(1)
	{
		printf("[%d]\n", tmp->content);
		tmp = tmp->next;
		if (tmp == head)
			break ;
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
