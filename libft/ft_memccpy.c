/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:39:41 by isghioua          #+#    #+#             */
/*   Updated: 2019/10/19 12:44:59 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*r;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dst;
	r = (unsigned char *)src;
	i = 0;
	while (i < n && r[i] != (unsigned char)c)
	{
		d[i] = r[i];
		i++;
	}
	if (r[i] == (unsigned char)c)
	{
		d[i] = r[i];
		return (dst + i + 1);
	}
	return (NULL);
}
