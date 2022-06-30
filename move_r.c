/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:20:59 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/21 14:46:10 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst, int i)
{
	t_list	*tmp;
	int		rk;

	if (!(*lst))
		return ;
	tmp = *lst;
	rk = (*lst)->rk;
	ft_lstadd_back(lst, ft_lstnew((*lst)->content));
	(*lst) = tmp->nx;
	ft_lstdelone(tmp, free);
	(ft_lstlast(*lst))->rk = rk;
	if (i == ra)
		printf("ra\n");
	if (i == rb)
		printf("rb\n");
}

void	ft_rrotate(t_list **lst, int i)
{
	t_list	*tmp;
	int		rk;

	if (!(*lst))
		return ;
	tmp = *lst;
	while ((tmp->nx)->nx)
		tmp = tmp->nx;
	rk = ((tmp->nx)->rk);
	ft_lstadd_front(lst, ft_lstnew((tmp->nx)->content));
	ft_lstdelone(tmp->nx, free);
	tmp->nx = NULL;
	(*lst)->rk = rk;
	if (i == rra)
		printf("rra\n");
	if (i == rrb)
		printf("rrb\n");
}

void	move_double_r(t_list **a, t_list **b, int i, t_stats stats)
{
	if (i == rr)
	{
		stats.stdsum_a = move(a, ra, stats);
		stats.stdsum_b = move(b, rb, stats);
		printf("rr\n");
	}
	if (i == rrr)
	{
		stats.stdsum_a = move(a, rra, stats);
		stats.stdsum_b = move(b, rrb, stats);
		printf("rrr\n");
	}
}
