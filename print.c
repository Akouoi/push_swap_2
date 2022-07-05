/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:28:03 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/05 19:06:23 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(char *str, char *name, t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	printf("\033[37;01m%s %s\033[00m", str, name);
	while (++i < 80)
		ft_putchar_fd('-', 1);
	write (1, "\n", 1);
	printf("\n\tpos\t|\trank\t|\tcost\t|\tcosta\t|\tcostb\t\n");
	tmp = *lst;
	while (tmp)
	{
		printf("\n\t%d :\t|\t%d\t|\t", tmp->pos, tmp->rk);
		if (tmp->cost_b < 0)
			printf("\033[31;01m%+d\033[00m\t|\t%+d\t|\t%+d\n",
				abs(tmp->cost_b) + abs(tmp->cost_a), tmp->cost_a, tmp->cost_b);
		else if (tmp->cost_b > 0)
			printf("\033[32;01m%+d\033[00m\t|\t%+d\t|\t%+d\n",
				abs(tmp->cost_b) + abs(tmp->cost_a), tmp->cost_a, tmp->cost_b);
		else
			printf("%+d \t|\t% d\n", abs(tmp->cost_b) + abs(tmp->cost_a), tmp->se);
		tmp = tmp->nx;
	}
	tmp = *lst;
	// write (1, "\n", 1);
	// i = 0;
	// while (++i < 80)
	// 	ft_putchar_fd('-', 1);
	// write (1, "\n", 1);
}

void	print_tab(char *str, t_list **a, t_list **b, t_stats stats)
{
	ft_print(str, "A", a);
	if (*b)
		ft_print(str, "B", b);
	printf("\nstd :%d\t|\tmd/sz %.1f/%.1f\n",
		stats.stdsum_a, stats.mid, stats.size);
}
