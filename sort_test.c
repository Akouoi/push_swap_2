/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:38:22 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/06 18:00:56 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_swap(t_list **a, t_list **b, t_stats stats)
{
	if (ft_lstsize(*a) == stats.size && stats.stdsum_a == 0)
		return (0);
	while ((*a) && b && (*a)->rk == (*b)->rk + 1)
		stats.stdsum_a = move(a, b, pa, stats);
	if (b && ((*a)->se > 0 && (*a)->se <= stats.mid)
		&& ((*b)->rk - (*b)->nx->rk < 0
			&& (*b)->rk - (*b)->nx->rk > -stats.mid))
		stats.stdsum_a = move(a, b, ss, stats);
	else if ((*a)->rk - (*a)->nx->rk > 0 && (*a)->rk - (*a)->nx->rk < stats.mid)
		stats.stdsum_a = move(a, b, sa, stats);
	else if (b && (*b)->rk - (*b)->nx->rk < 0
		&& (*b)->rk - (*b)->nx->rk > -stats.mid)
		stats.stdsum_b = move(a, b, sb, stats);
	sort_swap(a, b, stats);
	return (1);
}
	// print_tab("LISTE", a, b, stats);	

int	solve_sort(t_list **a, t_list **b, t_stats stats)
{
	t_list	*tmp;
	t_list	*min;
	// int	i;
	if (!(*b))
		return (1);
	print_tab("LISTE solve_sort", a, b, stats);
	tmp = *b;
	min = tmp;
	while (tmp)
	{
		tmp = tmp->nx;
		if (tmp)
			min = ft_min(min, tmp);
	}
	if(min->cost_a == 0)
	{
		while (min->pos != 1)
		{
			if (find_nx(a, min->rk + 1, stats) != 1 && min->pos != 1)
				stats.stdsum_a = move(a, b, rr, stats);
			else if (find_nx(a, min->rk + 1, stats) != 1 && min->pos == 1)
				stats.stdsum_a = move(a, b, ra, stats);
			else
				stats.stdsum_a = move(a, b, rb, stats);
		}
		stats.stdsum_a = move(a, b, pa, stats);
	}
	else
	{
		// print_tab("LISTE after push", a, b, stats);
		// printf("cost_a %d\tcost_b %d\t sum %d\n", min->cost_a, min->cost_b, abs(min->cost_b) + abs(min->cost_a));
		// while (find_nx(a, min->rk + 1, stats) != 1 || min->pos != 1)
		// {
			if (min->cost_a > 1 && min->pos != 1)
				stats.stdsum_a = move(a, b, rrr, stats);
			else if (min->cost_a > 1 && min->pos == 1)
				stats.stdsum_a = move(a, b, rra, stats);
			else
				stats.stdsum_a = move(a, b, rrb, stats);
		// }
			stats.stdsum_a = move(a, b, pa, stats);
	} 
	solve_sort(a, b, stats);
	return (0);
}

int sort_test(t_list **a, t_list **b, t_stats stats)
{

	stats.stdsum_a = ft_stdsum(a, stats);
	if (stats.stdsum_a == 0)
		return (0);
	while (ft_lstsize(*a) > (int)stats.mid + 1)
	{
		if ((*a)->rk < stats.mid)
			stats.stdsum_a = move(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, b, rra, stats);
	}
	print_tab("LISTE after push", a, b, stats);	
	stats.serie = ft_serie(a);
	printf("serie = %d\n", stats.serie);
	while (ft_lstsize(*a) - stats.serie && ft_lstsize(*a) > 4)
	{
		if ((*a)->se != -1 && ft_lstlast(*a)->rk != (*a)->rk - 1)
			stats.stdsum_a = move(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, b, rra, stats);
	}

	// if (ft_lstsize(*a) == stats.mid)
	// if (ft_lstsize(*a) == 3)
	// 	sort_three(a, stats);
	
	// get_cost_b(*a, *b, stats);

	// solve_sort(a, b, stats);
	// if (a && b)
		// sort_swap(a, b, stats);
	return(1);
}
