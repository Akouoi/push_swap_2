/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:15:22 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/04 14:43:38 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	move(t_list **lst, int i, t_stats stats)
{
	void	(*move[9])(t_list**, int);

	if (!(stats.size))
		return (0);
	move[sa] = ft_swap;
	move[ra] = ft_rotate;
	move[rra] = ft_rrotate;
	move[sb] = ft_swap;
	move[rb] = ft_rotate;
	move[rrb] = ft_rrotate;
	move[ss] = ft_swap;
	move[i](lst, i);
	ft_pos_shift(lst);
	return (ft_stdsum(lst, stats));
}

int	move_double(t_list **a, t_list **b, int i, t_stats stats)
{
	void	(*d_move[6])(t_list**, t_list**, int, t_stats);

	if (!(stats.size))
		return (0);
	d_move[ss - 6] = move_ss;
	d_move[pa - 6] = move_p;
	d_move[pb - 6] = move_p;
	d_move[rr - 6] = move_double_r;
	d_move[rrr - 6] = move_double_r;
	d_move[i - 6](a, b, i, stats);
	ft_pos_shift(a);
	if (b)
		ft_pos_shift(b);
	get_cost_b(*a, *b, stats);
	return (ft_stdsum(a, stats));
}
