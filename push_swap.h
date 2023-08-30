/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:08:08 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 18:54:10 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				num;
	int				index;
	int				flag;
}					t_list;

typedef struct s_push
{
	int				next;
	int				max;
	int				mid;
	int				flag;
}					t_push;

void				sort_and_partition(t_list **a, t_list **b, t_push *push,
						int count);
void				find_next_index(t_list **a, t_list **b, t_push *push);
void				push_a(t_list **a, t_list **b, t_push *push);
void				push_b(t_list **a, t_list **b, t_push *push);
void				big_sort(t_list **a, t_list **b, int count);

void				error(void);
int					ft_atoi(char *str);
void				ft_putstr_fd(char *s, int fd);

char				**ft_split(char const *s, char c);

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);

t_list				*find_min_val(t_list **stack);
t_list				*find_max_val(t_list **stack);
int					check_pos(t_list **stack, t_list *min);
int					stack_size(t_list **stack);
int					check_if_sorted(t_list **stack);

int					check_duplicates(t_list **stack);
int					stack_is_sorted(t_list **stack, int count);
void				set_index(t_list **stack);
void				free_stack(t_list *stack, int i);
void				free_both_stacks(t_list *a, t_list *b, int i);

void				sort_2_nums(t_list **stack);
void				sort_3_nums(t_list **stack);
void				sort_4_and_5_nums(t_list **a, t_list **b);
void				push_top3_min_to_b(t_list **a, t_list **b);

void				push_swap(t_list **a, int count);

void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);

void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

#endif
