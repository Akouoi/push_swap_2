/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:08:14 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/01 11:28:22 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] <= ' ')
		i++;
	sign = 1 - 2 * (str[i] == '-');
	if (str[i] == '+' || str[i] == '-')
			i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
/*
int	main()
{
	printf("%d\n", ft_atoi("-1"));
}*/