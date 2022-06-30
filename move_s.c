/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:20:21 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/22 19:06:50 by akouoi           ###   ########.fr       */
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
	if (*lst && (*lst)->next)
	{
		tmp->content = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = tmp->content;
	}
	ft_swap_int(&((*lst)->nb), (&((*lst)->next)->nb));
	ft_swap_int(&((*lst)->rank), (&((*lst)->next)->rank));
	if (i == sa)
		printf("sa\n");
	if (i == sb)
		printf("sb\n");
	free (tmp);
}

void	move_ss(t_list **a, t_list **b, int i, t_stats stats)
{
	(void)i;
	stats.stdsum_a = move(a, ss, stats);
	stats.stdsum_b = move(b, ss, stats);
	printf("ss\n");
}
