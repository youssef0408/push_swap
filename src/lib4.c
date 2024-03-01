/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:19:13 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/31 13:57:42 by yothmani         ###   ########.fr       */
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
		if (tmp->content < min->content)
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
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
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
			if ((tmp->content < min) && (tmp->index == -1))
			{
				min = tmp->content;
				min_list = tmp;
			}
			tmp = tmp->next;
		}
		min_list->index = j;
		j++;
	}
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

int	check_if_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
