/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:09:57 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/12 19:10:35 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*nn;
	void	*nc;

	nl = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		nc = f(lst->content);
		nn = ft_lstnew(nc);
		if (!nn)
		{
			if (nc)
			{
				del(nc);
				ft_lstclear(&nl, del);
				return (NULL);
			}
		}
		ft_lstadd_back(&nl, nn);
		lst = lst->next;
	}
	return (nl);
}
