/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:50:51 by aouhbi            #+#    #+#             */
/*   Updated: 2023/02/15 15:53:36 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*previous;
	int				*content;
	struct s_list	*next;
}	t_tavern;

t_tavern	*ft_lstlast(t_tavern *lst);
t_tavern	*ft_lstnew(void *content);
void		ft_lstadd_back(t_tavern **lst, t_tavern *new);
void		swap_a(t_tavern **head, int n);
void		swap_b(t_tavern **head, int n);
void		swap_a_b(t_tavern **ha, t_tavern **hb);
void		push_to_a(t_tavern **a, t_tavern **b);
void		push_to_b(t_tavern **a, t_tavern **b);
void		shift_up_stack_a(t_tavern **a, int n);
void		shift_up_stack_b(t_tavern **b, int n);
void		shift_up_stack_a_b(t_tavern **a, t_tavern **b);
void		shift_down_stack_a(t_tavern **a, int n);
void		shift_down_stack_b(t_tavern **b, int n);
void		shift_down_stack_a_b(t_tavern **a, t_tavern **b);
t_tavern	*feeding(char **s);
void		bubble_sort(int *arr, int n);
void		analyse_arg(char *str);
int			ft_strcmp(char s1, char s2);
size_t		ft_strlen(char *s);
long		ft_atoi(char *str);
void		analyse_arg2(char	*str);
void		error_out(void);
void		check_length(char *str);

#endif