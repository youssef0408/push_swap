/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:02 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 17:36:15 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_list **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
