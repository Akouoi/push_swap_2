/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:45:02 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/06 12:24:45 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
/*
int	main()
{
	t_list	*elem;
	t_list	*par;
	t_list	*next_par;
	par = malloc(sizeof(t_list));
	next_par = malloc(sizeof(t_list));

	par->content = "hello world";
	next_par->content = "coucou";

	par->next = next_par;
	printf("hello world address = %p\n", par->content);
	printf("coucou address = %p\n", par->next);
	printf("HW = %s\n", (char *)par->content);
	printf("CC = %s\n", (char *)next_par->content);
	printf("--------------------------\n");
	elem = ft_lstlast(par);
	printf("%s\n", (char *)elem->content);
	printf("%p\n", &elem->content);
	printf("--------------------------\n");
	printf("%s\n", (char *)par->content);
}
*/