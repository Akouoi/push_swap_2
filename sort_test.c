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
	// if(stats.stdsum_a == 0)
	// 	return (0);
	if (((*a)->serie > 0 && (*a)->serie <= stats.mid)
			&& ((*b)->rank - (*b)->next->rank < 0 && (*b)->rank - (*b)->next->rank > -stats.mid))
		stats.stdsum_a = move_double(a, b, ss, stats);
	else if ((*a)->rank - (*a)->next->rank > 0 && (*a)->rank - (*a)->next->rank < stats.mid)
		stats.stdsum_a = move(a, sa, stats);
	else if ((*b)->rank - (*b)->next->rank < 0 && (*b)->rank - (*b)->next->rank > -stats.mid)
		stats.stdsum_a = move(a, sa, stats);
	// sort_swap(a, b, stats);
	return(1);
}
int sort_test(t_list **a, t_list **b, t_stats stats)
{
	stats.serie = ft_serie(a);

	while (ft_lstsize(*a) != stats.mid && stats.stdsum_a != 0)
	{
		if ((*a)->rank <= stats.mid)
			stats.stdsum_a = move_double(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, ra, stats);
	}
	if (*a && *b)
		sort_swap(a, b, stats);
	while (*a && *b && (*a)->rank == (*b)->rank + 1)
		stats.stdsum_a = move_double(a, b, pa, stats);
	// print_tab("LISTE", a, b, stats);

	// sort_test(a, b, stats);
	return(1);
}
