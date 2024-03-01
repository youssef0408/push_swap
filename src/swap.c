/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:11:17 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 17:34:31 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_list **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
