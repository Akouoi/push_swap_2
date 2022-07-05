/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:22:40 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/05 19:04:25 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

//---------------------------------------------------------------------------------------

enum e_move
{
	sa,
	ra,
	rra,
	sb,
	rb,
	rrb,
	ss,
	pa,
	pb,
	rr,
	rrr
};

//---------------------------------------------------------------------------------------

typedef struct s_stats
{
	int		stdsum_a;
	int		stdsum_b;
	double	size;
	double	mid;
	int		serie;
	int		move;
}	t_stats;

//---------------------------------------------------------------------------------------
//		main.c
//---------------------------------------------------------------------------------------

int		pushswap(int ac, char **av);

//---------------------------------------------------------------------------------------
//		check_arg.c
//---------------------------------------------------------------------------------------

int		check_arg(int ac, char **av);

int		check_atoi(const char *nptr);

int		check_dup(t_list **lst);

//---------------------------------------------------------------------------------------
//		init.c
//---------------------------------------------------------------------------------------

t_list	**ft_lstset(int ac, char **av);

t_stats	ft_statset(t_list **lst);

//---------------------------------------------------------------------------------------
//		moves.c
//---------------------------------------------------------------------------------------

int		move_single(t_list **lst, int i, t_stats stats);

int		move(t_list **a, t_list **b, int i, t_stats stats);

//---------------------------------------------------------------------------------------
//		move_s.c
//---------------------------------------------------------------------------------------

void	ft_swap(t_list **lst, int i);

void	move_ss(t_list **a, t_list **b, int i, t_stats stats);

//---------------------------------------------------------------------------------------
//		move_r.c
//---------------------------------------------------------------------------------------

void	ft_rotate(t_list **lst, int i);

void	ft_rrotate(t_list **lst, int i);

void	move_double_r(t_list **a, t_list **b, int i, t_stats stats);

//---------------------------------------------------------------------------------------
//		moves_p.c
//---------------------------------------------------------------------------------------

void	move_p(t_list **a, t_list **b, int i, t_stats stats);

void	push(t_list **src, t_list **dst);

//---------------------------------------------------------------------------------------
//		refresh.c
//---------------------------------------------------------------------------------------

int		serie_calc(t_list *a);

int		ft_pos_shift(t_list **lst);

int		ft_stdsum(t_list **lst, t_stats stats);

int		ft_serie(t_list **lst);

t_list	*ft_lstmid(t_list **lst);

//---------------------------------------------------------------------------------------
//		math.c
//---------------------------------------------------------------------------------------

int		check_if(t_list **a, t_list **b, t_stats stats);

int		find_nx(t_list **a, int j, t_stats stats);

int		get_cost_b(t_list *a, t_list *b, t_stats stats);

int		abs(int i);

t_list	*ft_min(t_list *a, t_list *b);

//---------------------------------------------------------------------------------------
//		print,c
//---------------------------------------------------------------------------------------

void	ft_print(char *str, char *name, t_list **lst);

void	print_tab(char *str, t_list **a, t_list **b, t_stats stats);

//---------------------------------------------------------------------------------------
//		sort_two_three.c
//---------------------------------------------------------------------------------------

int		sort_three(t_list **lst, t_stats stats);

int		sort_two(t_list *lst, t_stats stats);


//---------------------------------------------------------------------------------------
//		bubble_sort.c
//---------------------------------------------------------------------------------------

int		bubble_sort(t_list *a, t_list *b, t_stats stats);

//---------------------------------------------------------------------------------------
//		quick_sort.c
//---------------------------------------------------------------------------------------

int		quick_sort(t_list **a, t_list **b, t_stats stats);

int		sort_test(t_list **a, t_list **b, t_stats stats);

#endif

// Couleurs pour print
// \033[31;01mrouge\033[00m
// \033[32;01mvert\033[00m
// \033[33;01mjaune\033[00m
// \033[34;01mbleu\033[00m
// \033[35;01mviolet\033[00m
// \033[36;01mturquoise\033[00m
// \033[37;01mblanc\033[00m
