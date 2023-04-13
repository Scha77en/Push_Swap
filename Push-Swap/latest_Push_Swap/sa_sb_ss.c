/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/13 07:47:00 by aouhbi           ###   ########.fr       */
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
