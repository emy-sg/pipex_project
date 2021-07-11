/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:53:45 by isghioua          #+#    #+#             */
/*   Updated: 2019/10/19 14:02:58 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *buf, const char *s, size_t size)
{
	void	*r;
	size_t	i;

	if (buf == NULL)
		return (0);
	r = buf;
	i = ft_strlen(s);
	while (size--)
	{
		if (size && *s)
		{
			*(unsigned char *)r = *(unsigned char *)s;
			s++;
			r++;
		}
		*(unsigned char *)r = '\0';
	}
	return (i);
}
