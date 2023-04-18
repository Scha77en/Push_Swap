/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:11:49 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/18 03:02:36 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	swap_a(t_tavern **head, int n)
{
	int	tmp;

	if (n == 1)
		write (1, "sa\n", 3);
	if (*head)
	{
		tmp = (*head)->content;
		if ((*head)->next)
		{
			(*head)->content = (*head)->next->content;
			(*head)->next->content = tmp;
		}
	}
}

void	swap_b(t_tavern **head, int n)
{
	int	tmp;

	if (n == 1)
		write (1, "sb\n", 3);
	if (*head)
	{
		tmp = (*head)->content;
		if ((*head)->next)
		{
			(*head)->content = (*head)->next->content;
			(*head)->next->content = tmp;
		}
	}
}

void	swap_a_b(t_tavern **ha, t_tavern **hb)
{
	swap_a(ha, 0);
	swap_b(hb, 0);
}
