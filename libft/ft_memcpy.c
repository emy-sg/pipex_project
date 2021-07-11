/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:36:54 by isghioua          #+#    #+#             */
/*   Updated: 2019/10/16 22:51:45 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*r;
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)src;
	r = (char *)dst;
	if (s == NULL && r == NULL)
		return (NULL);
	while (i < n)
	{
		r[i] = s[i];
		i++;
	}
	return (dst);
}
