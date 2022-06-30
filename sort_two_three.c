/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:12:33 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/26 13:13:46 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_two(t_list **lst, t_stats stats)
{

	if (stats.size == 2)
	{
		if ((*lst)->nb > ((*lst)->next)->nb)
		{
			stats.stdsum_a = move(lst, sa, stats);
			ft_lstclear(lst, free);
			return (1);
		}
		ft_lstclear(lst, free);
		return (0);
	}
	else if ((*lst)->rank == 1 && (*lst)->next->rank == stats.size)
	{
		stats.stdsum_a = move(lst, sa, stats);
		return (1);
	}
	return(0);
}

int	sort_three(t_list **lst, t_stats stats)
{
	if (ft_stdsum(lst, stats) == 0)
	{
		ft_lstclear(lst, free);
		return (0);
	}
	if (ft_stdsum(lst, stats) == 4 && (*lst)->rank == 3)
		ft_rotate(lst, ra);
	if (ft_stdsum(lst, stats) == 2)
		ft_swap(lst, sa);
	if ((*lst)->rank == 2 && ((*lst)->next)->nb == 3)
	{
		ft_rrotate(lst, rra);
		return (0);
	}
	sort_three(lst, stats);
	return (1);
}
