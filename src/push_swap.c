/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:14:27 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 18:53:10 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, int count)
{
	t_list	*b;

	b = NULL;
	if (!check_if_sorted(a))
		free_both_stacks(*a, b, 0);
	if (count == 2)
		sort_2_nums(a);
	else if (count == 3)
		sort_3_nums(a);
	else if (count == 4 || count == 5)
		sort_4_and_5_nums(a, &b);
	else if (count > 5)
		big_sort(a, &b, count);
	free_both_stacks(*a, b, 0);
}
