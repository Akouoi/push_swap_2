/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:20:21 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/05 17:38:19 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	c;

	c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap(t_list **lst, int i)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list *));
	if (!tmp)
		return ;
	if (*lst && (*lst)->nx)
	{
		tmp->content = (*lst)->content;
		(*lst)->content = (*lst)->nx->content;
		(*lst)->nx->content = tmp->content;
	}
	ft_swap_int(&((*lst)->nb), (&((*lst)->nx)->nb));
	ft_swap_int(&((*lst)->rk), (&((*lst)->nx)->rk));
	if (i == sa)
		printf("sa\n");
	if (i == sb)
		printf("sb\n");
	free (tmp);
}

void	move_ss(t_list **a, t_list **b, int i, t_stats stats)
{
	(void)i;
	stats.stdsum_a = move_single(a, ss, stats);
	stats.stdsum_b = move_single(b, ss, stats);
	printf("ss\n");
}