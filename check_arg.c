/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:17:37 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/24 15:17:22 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_atoi(const char *nptr)
{
	int			sign;
	int			i;
	long int	result;

	i = 0;
	result = 0;
	while (nptr[i] <= ' ')
		i++;
	sign = 1 - 2 * (nptr[i] == '-');
	if (nptr[i] == '+' || nptr[i] == '-')
			i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	result *= sign;
	return (result > 2147483647 || result < -2147483648);
}

int	check_number(char *str)
{
	if (ft_strlen(str + (str[0] == '-')) > 10)
		return (0);
	if (!(ft_isdigit(str[0]) || str[0] == '-'))
		return (0);
	if (str[0] == '-' && !ft_isdigit(str[1]))
		return (0);
	return (1);
}

int	check_dup(t_list **lst)
{
	t_list	*tmp;
	t_list	*cmp;

	cmp = *lst;
	while (cmp)
	{
		tmp = cmp->next;
		while (tmp)
		{
			if (cmp->nb == tmp->nb)
			{
				ft_lstclear(lst, free);
				return (1);
			}
			tmp = tmp->next;
		}
		cmp = cmp->next;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac > 2)
	{
		while (i < ac)
		{
			j = 0;
			if (check_number(av[i]) == 0)
				return (write(1, "Error\n", 6));
			while (av[i][j + 1])
			{
				if (!ft_isdigit(av[i][j + 1]))
					return (write(1, "Error\n", 6));
				j++;
			}
			if (check_atoi(av[i]) == 1)
				return (write(2, "Error\n", 6));
			i++;
		}
	}
	return (0);
}
