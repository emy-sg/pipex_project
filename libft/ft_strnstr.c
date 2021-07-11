/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:11:57 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:25:26 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	while (i <= (int)len)
	{
		if (ft_strncmp((haystack + i), needle, ft_strlen(needle)) == 0)
			return ((char *)haystack + i);
		len--;
		i++;
	}
	return (0);
}
