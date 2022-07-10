/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:25:42 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/10 10:25:05 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmid(t_list **lst)
{
	t_list	*tmp;
	double	i;

	i = ft_lstsize(*lst) / 2 + 1;
	tmp = *lst;
	while (--i)
		tmp = tmp->nx;
	return (tmp);
}

int	ft_pos_shift(t_list **lst)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->pos = ++j;
		tmp = tmp->nx;
	}
	return (j);
}

int	ft_stdsum(t_list **lst, t_stats stats)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *lst;
	(void)stats.size;
	while (tmp)
	{
		tmp->pos = ++j;
		tmp->gap = (tmp->rk - tmp->pos);
		if (tmp->gap < 0)
			i -= tmp->gap;
		else
			i += tmp->gap;
		tmp = tmp->nx;
	}
	stats.serie = ft_serie(lst);
	return (i);
}

int	serie_calc(t_list *a)
{
	int		i;
	t_list	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->nx && tmp->se == -1)
			i++;
		tmp = tmp->nx;
	}
	return (i);
}

int	ft_serie(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->nx)
	{
		tmp->se = tmp->rk - (tmp->nx)->rk;
		tmp = tmp->nx;
	}
	tmp->se = tmp->rk - (*lst)->rk;
	return (serie_calc(*lst));
}
	// printf("\tserie_calc = %d\t", serie_calc(lst));
