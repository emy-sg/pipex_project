/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 08:47:18 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/29 14:11:41 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ternary operator in c
 * if (number > 9223372036854775807)
 * 		return ((signe == 1) ? -1 : 0);
 **/

int	ft_atoi(const char *str)
{
	int		signe;
	size_t	number;

	signe = 1;
	number = 0;
	while (*(char *)str == ' ' || *(char *)str == '\t'
		|| *(char *)str == '\n' || *(char *)str == '\v'
		|| *(char *)str == '\f' || *(char *)str == '\r')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		if (number > 9223372036854775807 && signe == 1)
			return (-1);
		else if (number > 9223372036854775807)
			return (0);
		str++;
	}
	return (number * signe);
}
