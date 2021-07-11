/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:56:02 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:24:32 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	d(char const *s1, char const *s2)
{
	size_t	c;
	size_t	j;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		c = 0;
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				i++;
				c++;
				break ;
			}
			j++;
		}
		if (c == 0)
			break ;
	}
	return (i);
}

static size_t	f(char const *s1, char const *s2)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while ((int)i > 0)
	{
		if (ft_strchr(s2, s1[i]))
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	size_t	deb;
	size_t	fin;
	size_t	i;

	if (s1 == NULL)
		return (0);
	if (set == NULL || !(*s1) || !(*set))
		return (ft_strdup(s1));
	deb = d(s1, set);
	fin = f(s1, set);
	if (deb == ft_strlen(s1))
		return (ft_strdup(""));
	r = (char *)malloc((fin - deb + 2) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (deb <= fin)
	{
		r[i] = *((char *)s1 + deb);
		i++;
		deb++;
	}
	r[i] = '\0';
	return (r);
}
