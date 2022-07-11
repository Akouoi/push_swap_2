/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:12:33 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/11 11:03:47 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_little(t_list **a, t_list **b, t_stats stats, int k)
{
	if (k == 2)
		return (sort_two(*a, stats));
	if (k == 3)
		return (sort_three(a, stats));
	if (k > 3)
		return (sort_five(a, b, stats));
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	return (0);
}

int	sort_two(t_list *lst, t_stats stats)
{
	if (stats.size == 2)
	{
		if (lst->nb > (lst->nx)->nb)
		{
			stats.stdsum_a = move_single(&lst, sa, stats);
			ft_lstclear(&lst, free);
			return (1);
		}
		ft_lstclear(&lst, free);
		return (0);
	}
	else if (lst->rk == 1 && lst->nx->rk == stats.size)
	{
		stats.stdsum_a = move_single(&lst, sa, stats);
		return (1);
	}
	return (0);
}

int	sort_three(t_list **lst, t_stats stats)
{
	if (ft_serie(lst) == 2)
	// {
	// 	if (ft_stdsum(lst, stats) == 0)
	// 		ft_lstclear(lst, free);
		return (0);
	// }
	if ((*lst)->se > 0 && (*lst)->nx->se > 0)
	{
		stats.stdsum_a = move_single(lst, ra, stats);
		stats.stdsum_a = move_single(lst, sa, stats);
		if (ft_lstsize(*lst) == stats.size)
			ft_lstclear(lst, free);
		return (0);
	}
	if ((*lst)->se < 0 && (*lst)->rk > (*lst)->nx->nx->rk)
	{
		stats.stdsum_a = move_single(lst, rra, stats);
		return (0);
	}
	else if ((*lst)->nx->se < 0 && (*lst)->rk > (*lst)->nx->nx->rk)
		stats.stdsum_a = move_single(lst, ra, stats);
	else
		stats.stdsum_a = move_single(lst, sa, stats);
	sort_three(lst, stats);
	return (1);
}

int sort_five(t_list **a, t_list **b, t_stats stats)
{

	if(stats.stdsum_a == 0)
		return(0);
	while (ft_lstsize(*a) > 3)
			stats.stdsum_a = move(a, b, pb, stats);								// print_tab("LISTE push", a, b, stats);

	if (ft_lstsize(*a) == 3)
	{
		sort_three(a, stats);
		get_cost_b(*a, *b, stats);
//										print_tab("LISTE push", a, b, stats);
		solve_sort(a, b, stats);
	}
	return(1);
}