/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:20:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/31 14:15:18 by yothmani         ###   ########.fr       */
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
			if (tmp1->content == tmp2->content)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		i--;
	}
	return (0);
}

int	stack_validation(t_list **stack, int count)
{
	int	len;

	len = stack_size(stack);
	if (len != count)
		return (0);
	if (check_if_sorted(stack) == 1)
		return (0);
	return (1);
}

int	stack_size(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
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
