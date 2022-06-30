/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:27:29 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/30 12:52:09 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pushswap(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	t_stats	stats;
//	int		i = 0;

	a = ft_lstset(ac, av);
	if (!a)
		return (1);
	stats = ft_statset(a, stats);
	// print_tab("LISTE", a, a, stats);
	if (check_dup(a) == 1)
		return (0);
	if (ac == 3)
		return (sort_two(a, stats));
	if (ac == 4)
		return (sort_three(a, stats));
	b = malloc(sizeof(t_list **));
	if (!b)
		return (1);
	// while (++i < 3 && stats.stdsum_a != 0)
	// 	bubble_sort(a, b, stats);
	sort_test(a, b, stats);
	// print_tab("LISTE", a, a, stats);

	ft_lstclear(a, free);
	ft_lstclear(b, free);
	// printf("GG liste triee\n");
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (-1);
	if (check_arg(ac, av) == 6)
		return (0);
	pushswap(ac, av);
	// 	return (write(2, "Error\n", 6));
	return (0);
}
