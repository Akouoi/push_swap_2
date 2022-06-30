#include "push_swap.h"

int sort_test(t_list **a, t_list **b, t_stats stats)
{
	stats.serie = ft_serie(a);

	while (ft_lstsize(*a) != stats.mid)
	{
		if ((*a)->rank <= stats.mid)
			stats.stdsum_a = move_double(a, b, pb, stats);
		else
			stats.stdsum_a = move(a, ra, stats);
	}
	if (((*a)->rank - (*a)->next->rank > 0 && (*a)->rank - (*a)->next->rank < stats.mid)
			&& ((*b)->rank - (*b)->next->rank < 0 && (*b)->rank - (*b)->next->rank > -stats.mid))
		stats.stdsum_a = move_double(a, b, ss, stats);
	else if ((*a)->rank - (*a)->next->rank > 0 && (*a)->rank - (*a)->next->rank < stats.mid)
		stats.stdsum_a = move(a, sa, stats);
	else if ((*b)->rank - (*b)->next->rank < 0 && (*b)->rank - (*b)->next->rank > -stats.mid)
		stats.stdsum_a = move(a, sa, stats);
	print_tab("LISTE", a, b, stats);

	// sort_test(a, b, stats);
	return(1);
}
