/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:19:13 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 18:09:31 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min_val(t_list **stack)
{
	t_list	*min;
	t_list	*tmp;

	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_max_val(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num > max->num)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	check_pos(t_list **stack, t_list *min)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while ((tmp != min) && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
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

int	check_if_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
