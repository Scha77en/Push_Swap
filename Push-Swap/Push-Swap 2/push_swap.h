/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:50:51 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/12 22:42:04 by aouhbi           ###   ########.fr       */
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
	int				ma;
	int				mb;
	int				large;
	int				small;
	struct s_list	*next;
}	t_tavern;

void		ft_lstadd_back_d(t_tavern **lst, t_tavern *new, int v);
t_tavern	*ft_lstnew_d(int content);
char		**ft_split(char *s, char c);
t_tavern	*ft_lstlast(t_tavern *lst);
void		swap_a(t_tavern **head, int n);
void		swap_b(t_tavern **head, int n);
void		swap_a_b(t_tavern **sa, t_tavern **sb);
void		push_to_stack(t_tavern **stack_1, t_tavern **stack_2, int ref);
void		stack_check(t_tavern **stack);
void		shift_up_stack_a(t_tavern **sa, int n);
void		shift_up_stack_b(t_tavern **sb, int n);
void		shift_up_stack_a_b(t_tavern **sa, t_tavern **sb);
void		shift_down_stack_a(t_tavern **sa, int n);
void		shift_down_stack_b(t_tavern **sb, int n);
void		shift_down_stack_a_b(t_tavern **sa, t_tavern **sb);
void		swap_nodes(t_tavern **head);
void		analyse_arg(char *str);
int			ft_strcmp(char s1, char s2);
size_t		ft_strlen_d(char *s);
long		ft_atoi(char *str);
void		analyse_arg2(char	*str);
void		error_out(void);
void		check_length(char *str);
void		check_twin(t_tavern **sa, t_tavern *tmp);
void		handling_errors(int argc, char *argv[], t_tavern **sa);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
t_tavern	*min_value(t_tavern	**sa);
void		sort_index(t_tavern **sa, t_tavern **sb);
void		pushing_to_sb(t_tavern **sa, t_tavern **sb);

void		assign_value(t_tavern **sa, t_tavern **sb, t_tavern *final);
void		stack_things(t_tavern **sa, t_tavern **sb);
int			ft_lstsize(t_tavern *lst);
void		move_smallest(t_tavern **sa, t_tavern **sb);
void		sort_stack_a(t_tavern **sa);
void		smallest_node(t_tavern **head, int v);
void		calculate_moves(t_tavern **sa, t_tavern **sb);
void		set_moves_in_b(t_tavern **stack);
void		set_moves_in_a(t_tavern **sa, t_tavern **sb);
t_tavern	*find_best_move(t_tavern **stack);
int			node_position(t_tavern *current, t_tavern **stack);
void		put_values(t_tavern **sa, t_tavern **best);
int			check_smallest(t_tavern **stack);

// void		longestincrseb(t_tavern **sa, t_tavern **sb);
// int			countlis(t_tavern **sa);

void   		 index_stack(t_tavern **stack);
t_tavern    *get_next_min(t_tavern **stack);

#endif