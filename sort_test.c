/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:38:22 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/30 12:38:32 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_swap(t_list **a, t_list **b, t_stats stats)
{
	if (ft_lstsize(*a) == stats.size && stats.stdsum_a == 0)
		return (0);
	while (*a && *b && (*a)->rk == (*b)->rk + 1)
		stats.stdsum_a = move_double(a, b, pa, stats);
	if (*b && ((*a)->se > 0 && (*a)->se <= stats.mid)
			&& ((*b)->rk - (*b)->nx->rk < 0 && (*b)->rk - (*b)->nx->rk > -stats.mid))
		stats.stdsum_a = move_double(a, b, ss, stats);
	else if ((*a)->rk - (*a)->nx->rk > 0 && (*a)->rk - (*a)->nx->rk < stats.mid)
		stats.stdsum_a = move(a, sa, stats);
	else if (*b && (*b)->rk - (*b)->nx->rk < 0 && (*b)->rk - (*b)->nx->rk > -stats.mid)
		stats.stdsum_a = move(b, sb, stats);
	// print_tab("LISTE", a, b, stats);
	
	sort_swap(a, b, stats);
	return(1);
}
int sort_test(t_list **a, t_list **b, t_stats stats)
{
	// (void)b;
	stats.serie = ft_serie(a);
	// printf("int %d\t%.1f\n", (int)stats.mid, stats.mid);
	while (ft_lstsize(*a) != stats.size - (int)stats.mid && stats.stdsum_a != 0)
	{
		if ((*a)->rk <= stats.mid)
			stats.stdsum_a = move_double(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, rra, stats);
		// print_tab("LISTE", a, b, stats);
	}
	if (ft_lstsize(*a) == 3)
		sort_three(a, stats);
	if (*a && *b)
		sort_swap(a, b, stats);

	// print_tab("LISTE", a, b, stats);
	// sort_test(a, b, stats);
	return(1);
}
