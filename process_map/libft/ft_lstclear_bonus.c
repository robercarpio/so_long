/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:30:59 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/12 17:31:27 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*n;

	if (!lst || !del)
		return ;
	a = *lst;
	while (a)
	{
		n = a->next;
		ft_lstdelone(a, del);
		a = n;
	}
	*lst = NULL;
}
