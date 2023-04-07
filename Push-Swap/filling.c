/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:04:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/05 14:42:56 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_tavern	*feeding(char **s)
// {
// 	t_tavern	*node;
// 	t_tavern	*head;
// 	int			i;

// 	head = NULL;
// 	i = 0;
// 	while (s[i])
// 	{
// 		node = ft_lstnew(s[i]);
// 		ft_lstadd_back(&head, node);
// 		i++;
// 	}
// 	return (head);
// }

int getLISLength(t_tavern* head)
{
	t_tavern	*curr;
	int			n;

	if (!head)
		return (0);
	n = 0;
	curr = head;
	while (curr->next != head)
	{
		if (curr->content < curr->next->content)
			n++;
		curr = curr->next;
	}
	if (curr->content < head->content)
		n++;
	printf("LIS [%d]\n", n);
	return (n);
}

void markLISNodes(t_tavern* head) {
    if (!head) {
        return;
    }

    int lis_length = getLISLength(head);
    if (lis_length == 0) {
        return;
    }

    int n = 0;
    t_tavern* curr = head;
    while (curr->next != head) {
        if (curr->content < curr->next->content) {
            n++;
            if (n == lis_length) {
                curr->next->value = 1;
            }
        } else {
            n = 0;
        }
        curr = curr->next;
    }
    if (curr->content < head->content) {
        n++;
        if (n == lis_length) {
            head->value = 1;
        }
    } else {
        n = 0;
    }

    curr = head;
    while (1) {
        printf("%d\n", curr->content);
        curr = curr->next;
		if (curr == head)
			break ;
    }
	while (1)
	{
		if (curr->value == 1)
			printf("\n[%d]\n", curr->content);
		curr = curr->next;
		if (curr == head)
			break ;
	}
}

int main() {
    // example linked list
    // t_tavern* head2 = NULL;
    t_tavern* head = NULL;
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

    head->content = 3;
    head->next = second;
	head->previous = tenth;
	
    second->content = 4;
    second->next = third;
	second->previous = head;

    third->content = -1;
    third->next = fourth;
	third->previous = second;

    fourth->content = 9;
    fourth->next = fifth;
	fourth->previous = third;

    fifth->content = 0;
    fifth->next = sixth;
	fifth->previous = fourth;

    sixth->content = 11;
    sixth->next = seventh;
	sixth->previous = fifth;

    seventh->content = 6;
    seventh->next = eighth;
	seventh->previous = sixth;

    eighth->content = 1;
    eighth->next = nineth;
	eighth->previous = seventh;

    nineth->content = 2;
    nineth->next = tenth;
	nineth->previous = eighth;

    tenth->content = 10;
    tenth->next = head;
	tenth->previous = nineth;

    // printf("Linked List: ");
    // printList(head);

    // int lis_length = longest_inc_sub(&head);
    markLISNodes(head);
	// stack_things(&head, &head2);
    // int lis_length2 = longestincrseb(&head);
    // printf("Longest increasing subsequence length: {%d}\n", lis_length);
    // printf("Longest increasing subsequence length: --[%d]\n", lis_length2);

    return 0;
}
