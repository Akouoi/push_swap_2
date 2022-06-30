/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:31:04 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/17 16:24:05 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		size;

	c = c % 256;
	if (!(*s))
		return (NULL);
	size = ft_strlen(s) - 1;
	p = (char *)s;
	if (c == '\0')
		return (&p[size + 1]);
	while (size >= 0)
	{
		if (p[size] == c)
			return (&p[size]);
		size--;
	}
	return (NULL);
}
/*
int	main(int argc, char *av[])
{
	if (argc == 3)
	{
		char * result_ptr = ft_strrchr(av[1], av[2][0]);
		if (result_ptr)
			printf("%s\n", result_ptr);
		else
			puts("RESULT IS NULL");
	}
}*/