/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:32:51 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/12 09:56:18 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = (*lst)->nx;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
		// free(lst);
	}
}
