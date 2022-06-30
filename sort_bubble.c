/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:09:28 by akouoi            #+#    #+#             */
/*   Updated: 2022/06/26 13:37:09 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next(t_list **a, int j)
{
	int	i;
	t_list	*tmp;
	i = 0;

	tmp = *a;
	while (tmp)
	{
		if (tmp->rank != j + 1)
		{
			i++;
			tmp = tmp->next;
		}
		else
			break ;
	}
	if (i !=j)
		return (i);
	return (0);
}
//printf("\nrank_match %d", i);

int	bubble_sort(t_list **a, t_list **b, t_stats stats)
{
	int	i;
	(void)b;
	// if (stats.stdsum_a == 0)
		//print_tab("LISTE", a, b, stats);
	
	if (stats.stdsum_a == 0 && ft_lstsize(*a) == stats.size)
		return (1);
	stats.serie = ft_serie(a);
	printf("==========stats.serie=%d\n", stats.serie);
	printf("\tstd = %d\t %d = %.0f\n", stats.stdsum_a, ft_lstsize(*a), stats.size);
	
	// if(*b && (*b)->rank - (*a)->rank <= -1)
	// {
	// 	stats.move += 1;
	// 	printf("\t%d\t", stats.move);
	// 	stats.stdsum_a = move_double(a, b, pa, stats);
	// }
	printf("next = %d\n",find_next(a, (*a)->rank));
 	if ((*a)->serie <= stats.mid)
 	{
 		stats.move += 1;
 		printf("\t%d\t", stats.move);
 		stats.stdsum_a = move(a, sa, stats);
 	}
	// if((*a)->serie >= stats.mid || abs((*a)->gap) > stats.mid)
	// {
	// 	stats.move += 1;
	// 	//printf("\t%d\t", stats.move);
	// 	stats.stdsum_a = move_double(a, b, pb, stats);
	// }
	else if (find_next(a, (*a)->rank) < stats.mid)
	{
		i = 0;
		while (i < stats.serie)
		{
			stats.move += 1;
			printf("\t%d\t", stats.move);
			stats.stdsum_a = move(a, ra, stats);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i <= stats.serie - stats.mid)
		{
			stats.move += 1;
			printf("\t%d\t", stats.move);
			stats.stdsum_a = move(a, rra, stats);
			i++;
		}
	}
	print_tab("LISTE", a, b, stats);
	// bubble_sort(a, b, stats);
	return (0);
}

// int	bubble_sort(t_list **a, t_list **b, t_stats stats)
// {
// 	// int	next;

// 	(void)b;
// 	if (ft_stdsum(a, stats) == 0 && ft_lstsize(*a) == stats.size)
// 		return (1);
// 	// //printf("\tstdsum :%d\t|\tmid/size %.1f/%d\t", 
	// stats.stdsum_a, stats.mid, stats.size);
// 	// //printf("\trank %d\t", (*a)->rank);
// 	// next = find_next(a, (*a)->rank);
// 	if (abs((*a)->serie) >= stats.mid)
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move_double(a, b, pb, stats);
// 	}
// 	if(*b && (*b)->rank == (*a)->rank - 1)
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move_double(a, b, pa, stats);
// 	}
// 	if ((*a)->serie > 0 && (*a)->serie < stats.mid 
// 		&& (*b && (*b)->next && (*b)->rank - (*b)->next->rank == -1))
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move_double(a, b, ss, stats);
// 	}
// 	else if ((*a)->serie > 0 && (*a)->serie <= stats.mid)
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move(a, sa, stats);
// 	}
// 	else if(*b && (*b)->next && (*b)->rank - (*b)->next->rank == -1) // OK
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move(b, sb, stats);
// 	}
// 	if (stats.serie >= stats.mid)
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move(a, rra, stats);
// 	}
// 	else
// 	{
// 		stats.move += 1;
// 		//printf("\t%d\t", stats.move);
// 		stats.stdsum_a = move(a, ra, stats);
// 	}
// 	// //printf("\tnext = %d\t", next);
// 	bubble_sort(a, b, stats);
// 	return (0);
// }

// int	sort_rotate (t_list **a, t_list **b, t_stats stats)
// {
// 	t_list	*last_a;
// 	t_list	*last_b;
// 	t_list	*mid;

// 	(void)b;
// 	last_a = ft_lstlast(*a);
// 	last_b = ft_lstlast(*b);
// 	mid = ft_lstmid(a);

// 	// if (mid->rank >= stats.mid)
// 	// 	stats.stdsum_a = move(a, rra, stats);	
// 	// else 
// 		stats.stdsum_a = move(a, ra, stats);

// 	// if ((*a)->serie != -1)
// 	// {
// 	// 	if (mid
// 	// }
// 	//printf("first %d, last %d \n",(*a)->rank , last_a->rank);
// 	//printf("first %d, last %d \n",(*b)->rank , last_b->rank);

// 	if ((*a)->rank == last_a->rank - 1)
// 	if ((*a)->rank == last_a->rank + 1)
// 		stats.stdsum_a = move(a, ra, stats);
// 	if(*b && (*b)->next && (*b)->rank - (*b)->next->rank == -1) // OK
// 		stats.stdsum_a = move(b, sb, stats);
// 	if ((*a)->rank = last_a->rank + 1)
// 		stats.stdsum_a = move(a, rra, stats);
// 	last_a = ft_lstlast(*a);
// 	//printf("first %d, last %d \n",(*a)->rank , last_a->rank);
// 	//printf("first %d, last %d \n",(*a)->rank , last_a->rank);

// 	return (0);
// }
// int	sort(t_list **a, t_list **b, t_stats stats)
// {	
// 	int i;

// 	i = 1;
	// if (ft_stdsum(a, stats) == 0)
	// 	return (1);
// 	while ((*a)->rank != i)// && i < stats.size)
// 		stats.stdsum_a = move(a, ra, stats);
// 	while ((*a)->rank == i && i < stats.size)
// 	{
// 		stats.stdsum_a = move(a, ra, stats);
// 		i++;
// 	}
// 	sort_swap(a, b, stats);
// 	sort_push(a, b, stats);
// 	// if (sort_push(a, b, stats) == -1 && sort_swap(a, b, stats) == -1)
// 	// ft_//print("a_sort", a, stats);
// 	// if(*b)
// 	// 	ft_//print("b", b, stats);
// 	// sort(a, b, stats);
// 	return (0);
// }

// int	sort_swap(t_list **a, t_list **b, t_stats stats)
// {
// 	//printf("%d %d %.2f\n", (*a)->serie, (*b)->serie, stats.mid);
// 	if((*a)->serie > 0 && (*a)->serie < stats.mid && *b && (*b)->next && (*b)->serie < 0 && (*b)->serie >= -stats.mid) // OK
// 	{
// 		move_ss(a, b, stats);
// 		return(ss);
// 	}
// 	else if((*a)->serie > 0 && (*a)->serie < stats.mid)
// 	{
// 		stats.stdsum_a = move(a, sa, stats);
// 		return (sa);
// 	}
// 	else if(*b && (*b)->next &&(*b)->serie < 0 && (*b)->serie > -stats.mid)
// 	{
// 		stats.stdsum_a = move(b, sb, stats);
// 		return (sb);
// 	}
// 	return (-1);
// }

// int	sort_push(t_list **a, t_list **b, t_stats stats)
// {

// 	if(*b && (*b)->rank == (*a)->rank - 1)
// 	{
// 		stats.stdsum_a = move_double(a, b, pa, stats);
// 		return (pa);
// 	}
// 	return (-1);
// }

// int	check_if(t_list **a, t_list **b, t_stats stats)
// {
// 	// t_list	*last_a;
// 	// t_list	*last_b;
// 	t_list	*mid;
// 	int i;
// 	// (void)b;
// 	// last_a = ft_lstlast(*a);
// 	// last_b = ft_lstlast(*b);
// 	mid = ft_lstmid(a);
// 	i = find_next(a, b);
// 	if(*b && (*b)->rank == (*a)->rank - 1)
// 		return (pa);
// 	else if((*a)->serie > 0 && (*a)->serie <= stats.mid && (*b)->serie < 0
		// && (*b)->serie >= -stats.mid)//(*a)->serie < stats.mid && *b && (*b)->next
			// && (*b)->serie < 0 && (*b)->serie >= -stats.mid) // OK
// 		return(ss);
// 	else if((*a)->serie > 0 && (*a)->serie <= stats.mid)
// 		return (sa);
// 	else if(*b && (*b)->next && (*b)->serie < 0 && (*b)->serie >= -stats.mid)
// 		return (sb);
// 	else if((*a)->serie >= stats.mid)
// 		return (pb);
// 	// else if (last_a->rank == (*b)->rank + 1)
// 	// 	return (rra + pa);
// 	else if (mid->rank < stats.mid)
// 			return (ra * i * 100 + pa * 10);
// 	else
// 			return (rra * i * 100 + pa * 10);
// 	return (-1);
// }
// int	sort(t_list **a, t_list **b, t_stats stats)
// {
// 	int	index;
// 	int i;

// 	i = 0;
// 	if (ft_stdsum(a, stats) == 0)
// 		return (1);
// 	index = check_if(a, b, stats);
// 	// //printf(/*Tours = %d */" index = %d %d\n", /*i,*/ index, ss);
// 	if (index >= ss && index <= pb)
// 		stats.stdsum_a = move_double(a, b, index, stats);
// 	else if (index >= sa && index <= rra)
//  		stats.stdsum_a = move(a, index, stats);
// 	else if (index >= sb  && index <= rrb)
//  		stats.stdsum_b = move(b, index, stats);
// 	else if (index % (100 * ra)  == pa * 10)
// 	{
// 		while (index > pa * 10)
//  		{
// 			stats.stdsum_a = move(a, ra, stats);
// 			index -= 100 * ra;
// 		}
// 		stats.stdsum_a = move_double(a, b, pa, stats);
// 	}
// 	else if (index % (100 * rra) == pa * 10)
// 	{
// 		while (index >  pa * 10)
//  		{
// 			stats.stdsum_a = move(a, rra, stats);
// 			index -= 100 * rra;
// 			//2 elements perdus, a retrouver
// 		}
// 		stats.stdsum_a = move_double(a, b, pa, stats);
// 	}
	
// 	// ft_//print("LIST A", a, stats);
// 	// if(*b)
// 	// 	ft_//print("LIST B", b, stats);

// 	// sort_swap(a, b, stats);
// 	// sort_push(a, b, stats);
// 	i += 1;
// 	// sort(a, b, stats);
// 	return (i);
// }
