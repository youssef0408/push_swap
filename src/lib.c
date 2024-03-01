/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:17:05 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/31 14:07:00 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	error_42(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_flag(int flag)
{
	if (flag == 0)
	{
		error_42();
	}
}

static int	check_sign(char **str, int i, int *j)
{
	while (*str[i] == 32 || (*str[i] >= 9 && *str[i] <= 13))
		i++;
	if (*str[i] == '+' || *str[i] == '-')
	{
		if (*str[i] == '-')
			*j = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	n;
	int	flag;

	flag = 0;
	i = 0;
	m = 1;
	n = 0;
	i = check_sign(&str, i, &m);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		n = n * 10 + m * (str[i] - 48);
		i++;
		if ((m == 1 && n < 0) || (m == -1 && n > 0))
			error_42();
	}
	if (str[i])
		error_42();
	check_flag(flag);
	return (n);
}
