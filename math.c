/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:04:06 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/05 18:54:25 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int i)
{
	int	sign;

	sign = 1 - 2 * (i < 0);
	return (sign * i);
}

t_list	*ft_min(t_list *a, t_list *b)
{
	t_list	*min;

	if (abs(a->cost_a) + abs(a->cost_b) < (abs(b->cost_a)) + abs(b->cost_b))
		min = a;
	else
		min = b;
	return (min);
}

int	find_nx(t_list **a, int j, t_stats stats)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->rk == j + 1)
			return (tmp->pos);
		tmp = tmp->nx;
	}
	return (stats.size + 1);
}

int	get_cost_b(t_list *a, t_list *b, t_stats stats)
{
	int		next;
	t_list	*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->pos <= ft_lstsize(b) / 2)
			tmp->cost_b = tmp->pos;
		else
			tmp->cost_b = -(ft_lstsize(b) - tmp->pos + 1);
		next = find_nx(&a, tmp->rk, stats) - 1;
		if (next > (double)(ft_lstsize(a) / 2) + 1)
			next = - (ft_lstsize(a) - next);
		tmp->cost_a = next;
		tmp = tmp->nx;
	}
	return (0);
}
