/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/03 02:05:30 by aouhbi           ###   ########.fr       */
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
    t_tavern* head2 = NULL;
    t_tavern* head = NULL;
    t_tavern* second = NULL;
    t_tavern* third = NULL;
    t_tavern* fourth = NULL;
    t_tavern* fifth = NULL;
	t_tavern*	tmp = NULL;

    head = (t_tavern*) malloc(sizeof(t_tavern));
    second = (t_tavern*) malloc(sizeof(t_tavern));
    third = (t_tavern*) malloc(sizeof(t_tavern));
    fourth = (t_tavern*) malloc(sizeof(t_tavern));
    fifth = (t_tavern*) malloc(sizeof(t_tavern));

    head->content = 456;
    head->next = second;

    second->content = 2;
    second->next = third;

    third->content = 38;
    third->next = fourth;

    fourth->content = 4;
    fourth->next = fifth;

    fifth->content = 89;
    fifth->next = head;

	head2 = head;
	tmp = head;
	while (1)
	{
		printf("before swaping : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head)
			break ;
	}
	shift_up_stack_b(&head, 1);
	tmp = head;
	while (1)
	{
		printf("after swaping : %d\n", tmp->content);
		tmp = tmp -> next;
		if (tmp == head)
			break ;
	}
    return 0;
}
