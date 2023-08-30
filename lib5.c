/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:20:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 18:33:39 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	tmp1 = *stack;
	i = stack_size(stack);
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

int	stack_is_sorted(t_list **stack, int count)
{
	int	len;

	len = stack_size(stack);
	if (len != count)
		return (0);
	if (check_if_sorted(stack) == 1)
		return (0);
	return (1);
}

void	set_index(t_list **stack)
{
	t_list			*tmp;
	t_list			*min_list;
	long long int	min;
	int				i;
	int				j;

	i = stack_size(stack);
	j = 0;
	while (j < i)
	{
		min = LLONG_MAX;
		tmp = *stack;
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

	len = stack_size(&stack);
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

void	free_both_stacks(t_list *a, t_list *b, int i)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = stack_size(&a);
	size_b = stack_size(&b);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	while (size_a--)
	{
		tmp_a = a->next;
		free(a);
		a = NULL;
		a = tmp_a;
	}
	while (size_b--)
	{
		tmp_b = b->next;
		free(b);
		b = NULL;
		b = tmp_b;
	}
	exit(0);
}
