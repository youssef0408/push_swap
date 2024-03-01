/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:13:41 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 17:40:05 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*push_b;

	if (!(*b))
		return ;
	push_b = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = push_b;
	printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*push_a;

	if (!(*a))
		return ;
	push_a = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = push_a;
	printf("pb\n");
}
