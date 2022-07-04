/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:38:22 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/04 17:01:06 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_swap(t_list **a, t_list **b, t_stats stats)
{
	if (ft_lstsize(*a) == stats.size && stats.stdsum_a == 0)
		return (0);
	while ((*a) && b && (*a)->rk == (*b)->rk + 1)
		stats.stdsum_a = move_double(a, b, pa, stats);
	if (b && ((*a)->se > 0 && (*a)->se <= stats.mid)
		&& ((*b)->rk - (*b)->nx->rk < 0 && (*b)->rk - (*b)->nx->rk > -stats.mid))
		stats.stdsum_a = move_double(a, b, ss, stats);
	else if ((*a)->rk - (*a)->nx->rk > 0 && (*a)->rk - (*a)->nx->rk < stats.mid)
		stats.stdsum_a = move(a, sa, stats);
	else if (b && (*b)->rk - (*b)->nx->rk < 0 && (*b)->rk - (*b)->nx->rk > -stats.mid)
		stats.stdsum_b = move(b, sb, stats);
	// print_tab("LISTE", a, b, stats);	
	// sort_swap(a, b, stats);
	return(1);
}

int	solve_sort(t_list **a, t_list **b, t_stats stats)
{
	t_list	*tmp;
	t_list	*min;
	// int	i;
	if (!(*b))
		return (1);
	tmp = *b;
	min = tmp;
	while (tmp)
	{
		tmp = tmp->nx;
		if (tmp)
			min = ft_min(min, tmp);
	}
	if(min->pos < ft_lstsize(*b))
	{
		// print_tab("LISTE after push", a, b, stats);
		// printf("cost_a %d\tcost_b %d\t sum %d\n", min->cost_a, min->cost_b, abs(min->cost_b) + abs(min->cost_a));
		// while (find_nx(a, min->rk + 1, stats) != 1 || min->pos != 1 )
		// {
			if (find_nx(a, min->rk + 1, stats) != 1 && min->pos != 1)
				stats.stdsum_a = move_double(a, b, rr, stats);
			else if (find_nx(a, min->rk + 1, stats) != 1 && min->pos == 1)
				stats.stdsum_a = move(b, ra, stats);
			else
				stats.stdsum_a = move(b, rb, stats);
		// }
		stats.stdsum_a = move_double(a, b, pa, stats);
	}
	else
	{
		// print_tab("LISTE after push", a, b, stats);
		// printf("cost_a %d\tcost_b %d\t sum %d\n", min->cost_a, min->cost_b, abs(min->cost_b) + abs(min->cost_a));
		// while (find_nx(a, min->rk + 1, stats) != 1 || min->pos != 1)
		// {
			if (min->cost_a > 1 && min->pos != 1)
				stats.stdsum_a = move_double(a, b, rrr, stats);
			else if (min->cost_a > 1 && min->pos == 1)
				stats.stdsum_a = move(b, rra, stats);
			else
				stats.stdsum_a = move(b, rrb, stats);
		// }
			stats.stdsum_a = move_double(a, b, pa, stats);
	} 
	solve_sort(a, b, stats);
	return (0);
}

int sort_test(t_list **a, t_list **b, t_stats stats)
{

	// (void)b;
 
	stats.serie = ft_serie(a);
	// i = stats.size - 3;
	// printf("int %d\t%.1f\n", i, stats.size);
	if (stats.stdsum_a == 0)
		return (0);
	while (ft_lstsize(*a) > stats.mid)
	{
		if ((*a)->rk <= stats.mid)
			stats.stdsum_a = move_double(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, rra, stats);
	}
	print_tab("LISTE after push", a, b, stats);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->rk <= stats.size - 3)
			stats.stdsum_a = move_double(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, rra, stats);
	}
	// if (ft_lstsize(*a) == stats.mid)
	if (ft_lstsize(*a) == 3)
		sort_three(a, stats);
	
	// solve_sort(a, b, stats);
	print_tab("LISTE after push", a, b, stats);
	// if (a && b)
	// 	sort_swap(a, b, stats);
	return(1);
}
