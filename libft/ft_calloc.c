/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:05:28 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:32:46 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ch;

	if (count == 0 && size == 0)
	{
		count = 1;
		size = 1;
	}
	ch = (void *)malloc(count * size);
	if (!ch)
		return (0);
	ft_bzero(ch, count * size);
	return (ch);
}
