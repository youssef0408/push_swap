/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:16:32 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 18:34:27 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**split;
	t_list	*a;
	int		i;

	i = 0;
	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(split[i++])));
	}
	else
	{
		while (++i < argc)
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
	}
	if (check_duplicates(&a) == 1)
		free_stack(a, 1);
	push_swap(&a, stack_size(&a));
}
