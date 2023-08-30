/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:20:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 16:20:31 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_identical(t_list **stack1)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	tmp1 = *stack1;
	i = count_lst(stack1);
	while (i > 0)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->num == tmp2->num)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		i--;
	}
	return (0);
}

int	check_sorting_a(t_list **stack1, int count)
{
	int	len;

	len = count_lst(stack1);
	if (len != count)
		return (0);
	if (check_sorting(stack1) == 1)
		return (0);
	return (1);
}

void	set_index(t_list **stack1)
{
	t_list			*tmp;
	t_list			*min_list;
	long long int	min;
	int				i;
	int				j;

	i = count_lst(stack1);
	j = 0;
	while (j < i)
	{
		min = LLONG_MAX;
		tmp = *stack1;
		while (tmp)
		{
			if ((tmp->num < min) && (tmp->index == -1))
			{
				min = tmp->num;
				min_list = tmp;
			}
			tmp = tmp->next;
		}
		min_list->index = j;
		j++;
	}
}

void	free_stack(t_list *stack, int i)
{
	t_list	*tmp;
	int		len;

	len = count_lst(&stack);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	while (len--)
	{
		tmp = stack->next;
		free(stack);
		stack = NULL;
		stack = tmp;
	}
	exit(0);
}

void	free_stacks(t_list *stack1, t_list *stack2, int i)
{
	t_list	*tmp_one;
	t_list	*tmp_two;
	int		len_one;
	int		len_two;

	len_one = count_lst(&stack1);
	len_two = count_lst(&stack2);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	while (len_one--)
	{
		tmp_one = stack1->next;
		free(stack1);
		stack1 = NULL;
		stack1 = tmp_one;
	}
	while (len_two--)
	{
		tmp_two = stack2->next;
		free(stack2);
		stack2 = NULL;
		stack2 = tmp_two;
	}
	exit(0);
}
