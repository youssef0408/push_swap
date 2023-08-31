/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:15:02 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/31 14:24:32 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_partition(t_list **a, t_list **b, t_sort *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*a)->index <= push->pivot)
			pb(a, b);
		else
		{
			if (stack_size(b) > 1 && (((*b)->index) < (push->pivot / 2)))
				rr(a, b);
			else
				ra(a);
		}
	}
	push->max = push->pivot;
	push->pivot = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	find_next_index(t_list **a, t_list **b, t_sort *push)
{
	if (stack_size(b) > 0 && ((*b)->index == push->next))
		pa(a, b);
	else if ((*a)->index == push->next)
	{
		(*a)->flag = -1;
		ra(a);
		push->next++;
	}
	else if ((stack_size(b)) > 2 && ft_lstlast(*b)->index == push->next)
		rrb(b);
	else if ((*a)->next->index == push->next)
		sa(a);
	else if ((stack_size(a)) > 1 && ((*a)->next->index == push->next)
		&& ((*b)->next->index == push->next + 1))
		ss(a, b);
	else
		return ;
	find_next_index(a, b, push);
}

void	push_a(t_list **a, t_list **b, t_sort *push)
{
	int	size_b;
	int	i;

	i = -1;
	size_b = stack_size(b);
	while (stack_size(b) && ++i < size_b)
	{
		if ((*b)->index == push->next)
			find_next_index(a, b, push);
		else if ((*b)->index >= push->pivot)
		{
			(*b)->flag = push->flag;
			pa(a, b);
		}
		else if ((*b)->index < push->pivot)
			rb(b);
	}
	push->max = push->pivot;
	push->pivot = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	push_b(t_list **a, t_list **b, t_sort *push)
{
	int	now_flag;

	now_flag = (*a)->flag;
	if ((*a)->flag != 0)
	{
		while ((*a)->flag == now_flag)
		{
			if ((*a)->index != push->next)
				pb(a, b);
			find_next_index(a, b, push);
		}
	}
	else if ((*a)->flag == 0)
	{
		while ((*a)->flag != -1)
		{
			if ((*a)->index != push->next)
				pb(a, b);
			find_next_index(a, b, push);
		}
	}
	if (stack_size(b))
		push->max = (find_max_val(b))->index;
	push->pivot = (push->max - push->next) / 2 + push->next;
}

void	big_sort(t_list **a, t_list **b, int count)
{
	t_sort	push;

	set_index(a);
	push.next = find_min_val(a)->index;
	push.max = find_max_val(a)->index;
	push.pivot = push.max / 2 + push.next;
	push.flag = 0;
	sort_and_partition(a, b, &push, count);
	while (!(stack_validation(a, count)))
	{
		if (stack_size(b) == 0)
			push_b(a, b, &push);
		else
			push_a(a, b, &push);
	}
}
