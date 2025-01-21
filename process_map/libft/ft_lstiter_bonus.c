/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:44:08 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/12 18:44:45 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*a;

	if (!lst || !f)
	{
		return ;
	}
	a = lst;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
