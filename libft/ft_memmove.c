/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:40:29 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:31:28 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t len)
{
	char	*dst;
	char	*src;
	char	*d;
	char	*s;

	dst = (char *)str1;
	src = (char *)str2;
	if (dst == NULL && src == NULL)
		return (NULL);
	d = dst + len - 1;
	s = src + len - 1;
	if (d < s)
		return (ft_memcpy(dst, src, len));
	while (len)
	{
		*d = *s;
		d--;
		s--;
		len--;
	}
	return ((void *)dst);
}
