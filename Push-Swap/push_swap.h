/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:50:51 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/02 22:13:11 by aouhbi           ###   ########.fr       */
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
	int				content;
	int				value;
	struct s_list	*next;
}	t_tavern;

void		ft_lstadd_back_d(t_tavern **lst, t_tavern *new, int v);
t_tavern	*ft_lstnew_d(int content);
char		**ft_split(char *s, char c);
t_tavern	*ft_lstlast(t_tavern *lst);
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
size_t		ft_strlen_d(char *s);
int			ft_atoi(char *str);
void		analyse_arg2(char	*str);
void		error_out(void);
void		check_length(char *str);
void		check_twin(t_tavern **sa, t_tavern *tmp);
void		handling_errors(int argc, char *argv[], t_tavern **sa);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);

int			ft_lstsize(t_tavern *lst);

int	longest_inc_sub(t_tavern **head);
int	assign_value(t_tavern **head, t_tavern **final);
int	longestincrseb(t_tavern **heada);
int	countlis(t_tavern **heada);

#endif