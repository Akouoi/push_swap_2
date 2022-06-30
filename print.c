/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:28:03 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/30 14:23:48 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(char *str, char *name, t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	printf("\033[37;01m%s %s\033[00m\n", str, name);
	printf("\n\tpos\t|\trank\t|\tgap\t|\tserie\n");
	while (++i < 80)
		ft_putchar_fd('-', 1);
	write (1, "\n", 1);
	tmp = *lst;
	while (tmp)
	{
		printf("\n\t%d :\t|\t%d\t|\t", tmp->pos, tmp->rk);
		if (tmp->gap < 0)
			printf("\033[31;01m%+d\033[00m\t|\t%+d\n", tmp->gap, tmp->se);
		else if (tmp->gap > 0)
			printf("\033[32;01m%+d\033[00m\t|\t%+d\n", tmp->gap, tmp->se);
		else
			printf("%+d \t|\t% d\n", tmp->gap, tmp->se);
		tmp = tmp->nx;
	}
	write (1, "\n", 1);
	tmp = *lst;
	i = 0;
	while (++i < 60)
		ft_putchar_fd('-', 1);
	write (1, "\n", 1);
}

void	print_tab(char *str, t_list **a, t_list **b, t_stats stats)
{
	ft_print(str, "A", a);
	if (*b)
		ft_print(str, "B", b);
	printf("\nstd :%d\t|\tmd/sz %.1f/%.1f\n", stats.stdsum_a, stats.mid, stats.size);
}
