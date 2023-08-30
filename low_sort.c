/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:10:15 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 16:10:35 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sorting_two(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	sorting_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	c = (*stack)->next->next->num;
	if ((b > c) && (c > a))
	{
		sa(stack);
		ra(stack);
	}
	else if ((b > a) && (a > c))
		rra(stack);
	else if ((c > a) && (a > b))
		sa(stack);
	else if ((a > c) && (c > b))
		ra(stack);
	else if ((a > b) && (b > c))
	{
		sa(stack);
		rra(stack);
	}
}

void	sorting_five(t_list **stack1, t_list **stack2)
{
	push_min_lst(stack1, stack2);
	sorting_three(stack1);
	while (count_lst(stack2) > 0)
		pa(stack1, stack2);
}

void	push_min_lst(t_list **stack1, t_list **stack2)
{
	while (count_lst(stack1) > 3)
	{
		if ((check_pos(stack1, find_min_lst(stack1))) == 0)
			pb(stack1, stack2);
		else if ((check_pos(stack1, find_min_lst(stack1)))
			< (count_lst(stack1) / 2 + 1))
			ra(stack1);
		else
			rra(stack1);
	}
}