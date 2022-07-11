/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:27:29 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/11 14:18:24 by akouoi           ###   ########.fr       */
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
	// printf(" first %d\n", (*a)->nb);
	if (!a)
		return (1);
	stats = ft_statset(a);
	if (check_dup(a) == 1)
		return (write(2, "Error\n", 6));
	b = malloc(sizeof(t_list **));
	if (!b)
		return (1);
							// printf("%d\n", ac);
	stats.stdsum_a = move(a, b, pb, stats);
	// if (ac <= 6)
	// 	return(sort_little(a, b, stats, ac));
	// else
	// 	sort_test(a, b, stats);
							// print_tab("LISTE", a, b, stats);
							//print_tab("LISTE", a, b, stats);
	ft_lstclear(a, free);
	if(*b)
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
