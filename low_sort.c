/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:10:15 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 19:06:48 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nums(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	sort_3_nums(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	c = (*stack)->next->next->num;
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		rra(stack);
		sa(stack);
	}
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_4_and_5_nums(t_list **a, t_list **b)
{
	push_top3_min_to_b(a, b);
	sort_3_nums(a);
	while (stack_size(b) > 0)
		pa(a, b);
}

void	push_top3_min_to_b(t_list **a, t_list **b)
{
	while (stack_size(a) > 3)
	{
		if ((check_pos(a, find_min_val(a))) == 0)
			pb(a, b);
		else if ((check_pos(a, find_min_val(a))) < (stack_size(a) / 2 + 1))
			ra(a);
		else
			rra(a);
		if (check_if_sorted(a) == 0 && stack_size(b) == 0)
			break ;
	}
}
