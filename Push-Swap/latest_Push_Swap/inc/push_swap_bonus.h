/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:50:51 by aouhbi            #+#    #+#             */
/*   Updated: 2023/04/16 03:31:23 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_list
{
	struct s_list	*previous;
	int				content;
	int				value;
	int				mb;
	struct s_list	*next;
}	t_tavern;

typedef struct s_liist
{
	char			*content;
	struct s_liist	*next;
}	t_list;

void		checking_moves(t_tavern **sa, t_tavern **sb, char *line);
int			check_stack(t_tavern **sa);
int			stack_length(t_tavern **sa, int size);
char		**ft_split(char *s, char c);
size_t		ft_strlen(const char *s);
void		check_str(char *str, long i, long trigger);
size_t		ft_strlen_d(char *s);
long		ft_atoi(char *str);
void		error_out(void);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(char *content, ssize_t readed);
int			ft_lstchr(t_list *head, char *s, int v);
char		*allocate_to_line(t_list *head);
void		ft_lstclear(t_list *lst);
int			get_next_line(int fd, char **line);
void		save_for_list(int fd, t_list **head);
char		*get_the_line(t_list *head);
void		modify_list(t_list **head);
void		ft_lstadd_back_d(t_tavern **lst, t_tavern *new, int v);
t_tavern	*ft_lstnew_d(int content);
t_tavern	*ft_lstlast_d(t_tavern *lst);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_tavern *head);
void		push_to_stack(t_tavern **stack_1, t_tavern **stack_2, int ref);
void		stack_check(t_tavern **stack);
void		shift_up_stack_a(t_tavern **sa, int v);
void		shift_up_stack_b(t_tavern **sb, int v);
void		shift_up_stack_a_b(t_tavern **sa, t_tavern **sb);
void		shift_down_stack_a(t_tavern **sa, int v);
void		shift_down_stack_b(t_tavern **sb, int n);
void		shift_down_stack_a_b(t_tavern **sa, t_tavern **sb);
void		swap_a(t_tavern **head, int n);
void		swap_b(t_tavern **head, int n);
void		swap_a_b(t_tavern **ha, t_tavern **hb);
void		swap_a(t_tavern **head, int n);
void		swap_b(t_tavern **head, int n);
void		swap_a_b(t_tavern **ha, t_tavern **hb);
int			ft_strcmp(char *s1, char *s2);
void		check_length(char *str);
void		handling_errors(int argc, char *argv[], t_tavern **sa);
void		check_twin(t_tavern **sa, t_tavern *tmp);
void		analyse_arg(char *str);
void		kay_oh(void);
void		free_mem(char **ptr, int j);

#endif