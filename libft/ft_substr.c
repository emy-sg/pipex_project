/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:49:36 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:22:12 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*sub;

	j = 0;
	i = 0;
	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[i] && i != start)
		i++;
	sub = (char *)malloc(len * sizeof(char) + 1);
	if (!sub)
		return (0);
	while (s[i] && len)
	{
		sub[j] = s[i];
		j++;
		i++;
		len--;
	}
	sub[j] = '\0';
	return (sub);
}
