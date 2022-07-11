/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:38:22 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/11 10:55:59 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
										// print_tab("LISTE solve_sort", a, b, stats);
	if (min->cost_a == 0 && min->cost_b == 0)
		stats.stdsum_a = move(a, b, pa, stats);
	else if (min->cost_a * min->cost_b > 0)
		stats.stdsum_a = move(a, b, rr + (min->cost_a < 0), stats);
	else if (min->cost_a * min->cost_b < 0)
	{
		stats.stdsum_a = move(a, b, ra + (min->cost_a < 0), stats);
		stats.stdsum_a = move(a, b, rb + (min->cost_b < 0), stats);
	}
	else if (min->cost_a != 0 && min->cost_b == 0)
		stats.stdsum_a = move(a, b, ra + (min->cost_a < 0), stats);
	else if (min->cost_b != 0 && min->cost_a == 0)
		stats.stdsum_a = move(a, b, rb + (min->cost_b < 0), stats);
	// }
										// print_tab("LISTE solve_sort", a, b, stats);
	solve_sort(a, b, stats);
	return (0);
}

int sort_test(t_list **a, t_list **b, t_stats stats)
{
	int m;

	if(stats.stdsum_a == 0)
		return(0);
	m = 0;
	if (ft_lstsize(*a) < 6)
		stats.move = 3;
	else
		stats.move -= ft_lstsize(*a) / 3;
//										printf("size = %.-1f\t move %.0f\n", stats.size, stats.move);
	while (ft_lstsize(*a) > (int)stats.move)
	{
		if ((*a)->rk < (stats.size - stats.move) + 1)
			stats.stdsum_a = move(a, b, pb, stats);
		// else if ((*a)->se == 1 || (*b)->se == -1)
		// 	stats.stdsum_a = move(a, b, sa, stats) * ((*a)->se == 1) +  move(a, b, sa, stats) * ((*b)->se == -1);
		else
		{
			if (find_nx(a, ++m, stats) > (int)(stats.size - stats.move) / 2 + 1)
				stats.stdsum_a = move(a, b, rra, stats);
			else
				stats.stdsum_a = move(a, b, ra, stats);
		}
		if ((*a)->rk < (stats.size - stats.move))
			stats.stdsum_a = move(a, b, pb, stats);
										// print_tab("LISTE push", a, b, stats);
	}
										// printf("serie = %d\n", stats.serie);
	// while (ft_lstsize(*a) > 3)
	// {
	// 	// if ((*a)->se != -1 && ft_lstlast(*a)->rk != (*a)->rk - 1)
	// 	if ((*a)->rk < stats.mid + 1)
	// 		stats.stdsum_a = move(a, b, pb, stats);
	// 	else
	// 	{
	// 		if (find_nx(a, 0, stats) < stats.mid)
	// 			stats.stdsum_a = move(a, b, ra, stats);
	// 		else
	// 			stats.stdsum_a = move(a, b, rra, stats);
	// 	}
	// }
										// printf("\nsort tested\n");
	// if (ft_lstsize(*a) == stats.mid)
	if (ft_lstsize(*a) == 3)
	{
		sort_three(a, stats);
		get_cost_b(*a, *b, stats);
//										print_tab("LISTE push", a, b, stats);
		solve_sort(a, b, stats);
	}
	// 									printf("---\nsort test\n");
	// }
										// print_tab("LISTE after push", a, b, stats);	
	// if (a && b)
		// sort_test(a, b, stats);
	return(1);
}

// int	sort_swap(t_list **a, t_list **b, t_stats stats)
// {
// 	if (ft_lstsize(*a) == stats.size && stats.stdsum_a == 0)
// 		return (0);
// 	while ((*a) && b && (*a)->rk == (*b)->rk + 1)
// 		stats.stdsum_a = move(a, b, pa, stats);
// 	if (b && ((*a)->se > 0 && (*a)->se <= stats.mid)
// 		&& ((*b)->rk - (*b)->nx->rk < 0
// 			&& (*b)->rk - (*b)->nx->rk > -stats.mid))
// 		stats.stdsum_a = move(a, b, ss, stats);
// 	else if ((*a)->rk - (*a)->nx->rk > 0 && (*a)->rk - (*a)->nx->rk < stats.mid)
// 		stats.stdsum_a = move(a, b, sa, stats);
// 	else if (b && (*b)->rk - (*b)->nx->rk < 0
// 		&& (*b)->rk - (*b)->nx->rk > -stats.mid)
// 		stats.stdsum_b = move(a, b, sb, stats);
// 	sort_swap(a, b, stats);
// 	return (1);
// }
	// print_tab("LISTE", a, b, stats);	

