/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:19:07 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/26 12:12:34 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stats	ft_statset(t_list **lst, t_stats stats)
{
	t_list	*tmp;
	t_list	*start;
	int		i;

	stats.size = 0;
	start = *lst;
	while (*lst)
	{
		tmp = start;
		i = 1;
		while (tmp)
		{
			i += ((*lst)->nb > tmp->nb);
			tmp = tmp->next;
		}
		(*lst)->rank = i;
		*lst = (*lst)->next;
		stats.size += 1;
	}
	stats.move = 0;
	*lst = start;
	stats.stdsum_a = ft_stdsum(lst, stats);
	stats.stdsum_b = 0;
	stats.mid = stats.size / 2;
	return (stats);
}

t_list	**ft_lstset(int ac, char **av)
{
	t_list	**lst;
	int		i;

	lst = malloc(sizeof(t_list **));
	if (!lst)
		return (NULL);
	i = 0;
	*lst = NULL;
	while (++i < ac)
		ft_lstadd_back(lst, ft_lstnew(av[i]));
	return (lst);
}
