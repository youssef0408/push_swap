/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:08:08 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 16:25:34 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	int				num;
	int				index;
	int				flag;
}	t_list;

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

int		get_next_line(char **line, int fd);
int		check_sorting_a(t_list **stack1, int count);
void	big_sorting(t_list **stack1, t_list **stack2, int count);
void	sorting_two(t_list **stack);
void	sorting_three(t_list **stack);
void	sorting_five(t_list **stack1, t_list **stack2);
void	set_index(t_list **stack1);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_putstr_fd(char *s, int fd);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack1, t_list **stack2);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack1, t_list **stack2);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack1, t_list **stack2);
void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);
int		check_pos(t_list **stack, t_list *min);
int		count_lst(t_list **stack);
void	push_min_lst(t_list **stack1, t_list **stack2);
int		check_identical(t_list **stack1);
int		check_sorting(t_list **stack1);
void	sorting(t_list **stack1, int count);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	free_stacks(t_list *stack1, t_list *stack2, int i);
void	free_stack(t_list *stack, int i);

#endif