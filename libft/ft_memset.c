/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:01:58 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:35:15 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*r;

	r = b;
	while (len)
	{
		*(unsigned char *)r = (unsigned char)c;
		r++;
		len--;
	}
	return ((void *)b);
}
