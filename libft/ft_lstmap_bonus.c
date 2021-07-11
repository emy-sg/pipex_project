/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:52:15 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 17:37:54 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_cr(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (*lst)
	{
		node = *lst;
		while (node)
		{
			tmp = node;
			node = node->next;
			if (tmp->content && del)
				del(tmp->content);
			free(tmp);
		}
		*lst = NULL;
		return (0);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rs;
	t_list	*node;

	node = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		if (node == NULL)
		{
			rs = ft_lstnew((*f)(lst->content));
			if (!rs && !f(lst->content))
				return (NULL);
			node = rs;
		}
		else
		{
			node->next = ft_lstnew(f(lst->content));
			if (!(node->next))
				return (ft_cr(&rs, del));
			node = node->next;
		}
		lst = lst->next;
	}
	return (rs);
}
