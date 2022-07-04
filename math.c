/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:04:06 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/04 14:49:28 by akouoi           ###   ########.fr       */
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
	// printf("min = %d\n", abs(min->cost_b) + abs(min->cost_a));
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
	return (stats.size);
}

int	get_cost_b(t_list *a, t_list *b, t_stats stats)
{
	int		next;
	t_list	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->cost_b = tmp->pos - 1;
		next = find_nx(&a, tmp->rk, stats);
		// printf("b->nb %d\tnext = %d\n", tmp->nb, next);
		tmp->cost_a = next - ft_lstsize(a) * (next > ft_lstsize(a) / 2);
		// printf("cost_a %d\tcost_b %d\t sum %d\n", tmp->cost_a, tmp->cost_b, abs(tmp->cost_b) + abs(tmp->cost_a));
		tmp = tmp->nx;
	}
	return (0);
}
