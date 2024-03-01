/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 17:38:07 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
