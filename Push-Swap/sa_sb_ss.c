/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/07 16:46:08 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_tavern **head, int n)
{
	t_tavern	*temp;

	if (*head == NULL || (*head)-> next == NULL)
		return ;
	temp = (*head)-> next;
	(*head)-> next = temp -> next;
	temp -> next = *head;
	*head = temp;
	if (n == 1)
		write (1, "sa\n", 3);
}

void	swap_b(t_tavern **head, int n)
{
	t_tavern	*temp;

	if (*head == NULL || (*head)-> next == NULL)
		return ;
	temp = (*head)-> next;
	(*head)-> next = temp -> next;
	temp -> next = *head;
	*head = temp;
	if (n == 1)
		write (1, "sb\n", 3);
}

void	swap_a_b(t_tavern **ha, t_tavern **hb)
{
	swap_a(ha, 0);
	swap_b(hb, 0);
	write (1, "ss\n", 3);
}

// int main(void)
// {
//     t_tavern *head = NULL;
//     t_tavern *second = NULL;
//     t_tavern *third = NULL;

//     head = (t_tavern *)malloc(sizeof(t_tavern));
//     second = (t_tavern *)malloc(sizeof(t_tavern));
//     third = (t_tavern *)malloc(sizeof(t_tavern));

//     head->content = "1";
//     head->next = second;

//     second->content = "2";
//     second->next = third;

//     third->content = "3";
//     third->next = NULL;

//     printf("Before swapping: \n");
//     t_tavern *temp = head;
//     while (temp != NULL)
//     {
//         printf("%s\n", temp->content);
//         temp = temp->next;
//     }

//     swap_b(&head);

//     printf("After swapping: \n");
//     temp = head;
//     while (temp != NULL)
//     {
//         printf("%s\n", temp->content);
//         temp = temp->next;
//     }

//     return 0;
// }