/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:12:33 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/05 17:35:47 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return(0);
}
//3 2 1 sa rra > >
int	sort_three(t_list **lst, t_stats stats)
{
	// printf("sort_three\n\n");
	if ((*lst)->se < 0  && (*lst)->nx->se < 0)
	{
		if (ft_lstsize(*lst) == stats.size)
			ft_lstclear(lst, free);
		return (0);
	}
	if ((*lst)->se > 0  && (*lst)->nx->se > 0)
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
	else if ((*lst)->se > 0  && (*lst)->nx->se < 0 && (*lst)->rk > (*lst)->nx->nx->rk)
		stats.stdsum_a = move_single(lst, ra, stats);
	else
		stats.stdsum_a = move_single(lst, sa, stats);
	sort_three(lst, stats);
	return (1);
}
