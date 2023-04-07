/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/07 01:50:53 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_tavern **head, int n)
{
	t_tavern	*temp;
	t_tavern	*curr;

	temp = *head;
	curr = *head;
	*head = (*head)->next;
	while (curr->next != temp)
		curr = curr->next;
	curr->next = *head;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if (n == 1)
		write (1, "sa\n", 3);
}

void	swap_b(t_tavern **head, int n)
{
	t_tavern	*temp;
	t_tavern	*curr;

	temp = *head;
	curr = *head;
	*head = (*head)->next;
	while (curr->next != temp)
		curr = curr->next;
	curr->next = *head;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if (n == 1)
		write (1, "sb\n", 3);
}

void	swap_a_b(t_tavern **ha, t_tavern **hb)
{
	swap_a(ha, 0);
	swap_b(hb, 0);
	write (1, "ss\n", 3);
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

    head->content = 10;
    head->next = second;
	head->previous = tenth;
	
    second->content = 20;
    second->next = third;
	second->previous = head;

    third->content = 30;
    third->next = fourth;
	third->previous = second;

    fourth->content = 40;
    fourth->next = fifth;
	fourth->previous = third;

    fifth->content = 50;
    fifth->next = sixth;
	fifth->previous = fourth;

    sixth->content = 60;
    sixth->next = seventh;
	sixth->previous = fifth;

    seventh->content = 70;
    seventh->next = eighth;
	seventh->previous = sixth;

    eighth->content = 80;
    eighth->next = nineth;
	eighth->previous = seventh;

    nineth->content = 90;
    nineth->next = tenth;
	nineth->previous = eighth;

    tenth->content = 100;
    tenth->next = head;
	tenth->previous = nineth;
			puts("----a----");
	tmp = head;
	while (tmp)
	{
		printf("content : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head)
			break ;
	}
		puts("----b----");
	tmp = head2;
	while (tmp)
	{
		printf("content : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head2)
			break ;
	}

	push_to_stack(&head, &head2, 1);
	push_to_stack(&head, &head2, 1);
	push_to_stack(&head, &head2, 1);
	push_to_stack(&head, &head2, 1);
	push_to_stack(&head, &head2, 1);
	push_to_stack(&head, &head2, 1);

		puts("----a----");
	tmp = head;
	while (tmp)
	{
		printf("content : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head)
			break ;
	}
		puts("----b----");
	tmp = head2;
	while (tmp)
	{
		printf("content : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head2)
			break ;
	}
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
	push_to_stack(&head2, &head, 0);
			puts("----a----");
	tmp = head;
	while (tmp)
	{
		printf("content : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head)
			break ;
	}
		puts("----b----");
	tmp = head2;
	while (tmp)
	{
		printf("content : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head2)
			break ;
	}

	// push_to_a(&head, &head2);
	// tmp = head2;
	// while (1)
	// {
	// 	printf("content : %d\n", tmp->content);
	// 	tmp = tmp -> next;
	// 	if (tmp == head2)
	// 		break ;
	// }
}
