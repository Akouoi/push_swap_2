/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:21:41 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/22 19:06:30 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_p(t_list **a, t_list **b, int i, t_stats stats)
{
	if (i == pb && *a)
	{
		push(a, b);
		printf("pb\n");
	}
	if (i == pa && *b)
	{	
		push(b, a);
		printf("pa\n");
	}
	stats.stdsum_a = ft_stdsum(a, stats);
	if (*b)
		stats.stdsum_b = ft_stdsum(b, stats);
}

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (dst && !(*src)->next)
	{
		ft_lstadd_front(dst, ft_lstnew((*src)->content));
		(*dst)->rank = (*src)->rank;
		ft_lstdelone(*src, free);
		*src = NULL;
	}
	else if ((*src)->next)
	{
			tmp = (*src)->next;
		if (dst && *src)
			ft_lstadd_front(dst, ft_lstnew((*src)->content));
		else
			(*dst) = ft_lstnew((*src)->content);
		(*dst)->rank = (*src)->rank;
		ft_lstdelone(*src, free);
		*src = tmp;
	}
}