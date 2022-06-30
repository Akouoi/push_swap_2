#include "push_swap.h"

int sort_test(t_list **a, t_list **b, t_stats stats)
{
	if(ft_lstsize(*a) == stats.mid)
		return (0);
	if ((*a)->rank < stats.mid)
		stats_stdsum_a = move_double(a, b, pb, stats);
	else
		stats_stdsum_a = move(a, ra, stats);
	sort_test(a, b, stats);
	return(1);
}
