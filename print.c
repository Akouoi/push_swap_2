/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:28:03 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/11 10:49:06 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(char *str, char *name, t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	printf("\t\033[37;01m%s %s\033[00m", str, name);
	while (++i < 50)
		ft_putchar_fd('-', 1);
	// write (1, "\n", 1);
	printf("\n\tpos\trank\tcost\tserie\tcosta\tcostb\n");
	tmp = *lst;
	while (tmp)
	{
		printf("\t%d :\t%d\t", tmp->pos, tmp->rk);
		printf("%+d\t%+d\t%+d", abs(tmp->cost_b) + abs(tmp->cost_a), tmp->se, tmp->cost_a);
		if (tmp->cost_b < 0)
			printf("\t\033[31;01m%+d\033[00m\n", tmp->cost_b);
		else if (tmp->cost_b > 0)
			printf("\t\033[32;01m%+d\033[00m\n", tmp->cost_b);
		else
			printf("\t%+d\n", tmp->cost_b);
		tmp = tmp->nx;
	}
	tmp = *lst;
}

void	print_tab(char *str, t_list **a, t_list **b, t_stats stats)
{
	ft_print(str, "A", a);
	if (*b)
		ft_print(str, "B", b);
	printf("\nstd :%d\tmd/sz %.1f/%.1f\n",
		stats.stdsum_a, stats.mid, stats.size);
}
