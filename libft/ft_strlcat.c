/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:17:13 by isghioua          #+#    #+#             */
/*   Updated: 2019/10/16 09:39:45 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	initial;
	size_t	a;

	a = ft_strlen(src);
	initial = 0;
	if (size < ft_strlen(dst))
		return (a + size);
	while (*dst)
	{
		dst++;
		initial++;
		size--;
	}
	while (size > 1 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (a + initial);
}
