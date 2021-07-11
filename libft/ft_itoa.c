/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:04:49 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:33:29 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num(int n)
{
	int	d;

	d = 0;
	if (n <= 0)
		d++;
	while (n)
	{
		d++;
		n = n / 10;
	}
	return (d);
}

static	char	*rem(char *ch, int c, int n, int w)
{
	unsigned int	nbr;
	int				i;

	nbr = n;
	i = w - 1;
	while (nbr > 9 && i > c)
	{
		ch[i] = (nbr % 10) + '0';
		nbr = (nbr / 10);
		i--;
	}
	ch[i] = nbr + '0';
	ch[w] = '\0';
	return (ch);
}

char	*ft_itoa(int n)
{
	int		i;
	int		w;
	char	*ch;

	i = 0;
	w = num(n);
	ch = (char *)malloc((w + 1) * sizeof(char));
	if (!ch)
		return (0);
	if (n < 0)
	{
		ch[i++] = '-';
		n = -n;
	}
	ch = rem(ch, i, n, w);
	return (ch);
}
