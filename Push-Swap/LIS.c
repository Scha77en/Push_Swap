/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:15 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/02 02:59:37 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	longest_inc_sub(t_tavern **head)
{
	int			length;
	int			max_length;
	t_tavern	*compare;
	t_tavern	*search;

	assign_value(&search)
}

void	stack_things(t_tavern **sa, t_tavern **sb)
{
	int		i;

	i = longest_inc_sub(&sa);
	while (i < ft_lstsize(*sa))
	{
		if (sa -> value == 0)
		{
			push_to_b(&sa,&sb);
			i++;
		}
		else
			shift_up_stack_a(&sa, 1);
	}
	
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int lengthOfLIS(struct Node* head)
{
    int length = 0;
    int max_length = 0;
    int prev_value = -1;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > prev_value) {
            length++;
            if (length > max_length) {
                max_length = length;
            }
        } else {
            length = 1;
        }
        prev_value = current->data;
        current = current->next;
    }
    return max_length;
}




void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // example linked list
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));
    fifth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = fifth;

    fifth->data = 6;
    fifth->next = NULL;

    printf("Linked List: ");
    printList(head);

    int lis_length = lengthOfLIS(head);
    printf("Longest increasing subsequence length: %d\n", lis_length);

    return 0;
}

// write a function that compare a single node content with all other contents in the list, if the content of the other node is bigger than the content of the
// current node, assign to its value 1, and if its begger or equal to it assign to its value 0.
// after that swap the original list with sa, and again check the LIS, if the if the result of LIS after the sa is begger than the previous one, print sa and save the list.