/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:42:49 by greita            #+#    #+#             */
/*   Updated: 2021/11/18 11:12:30 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_elem = ft_lstnew((*f)(lst -> content));
	if (!new_elem)
		return (NULL);
	new_lst = new_elem;
	lst = lst -> next;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst -> content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst -> next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}
