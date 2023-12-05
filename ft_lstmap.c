/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:16:10 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:21:09 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;
	t_list	*prev;

	list = NULL;
	prev = NULL;
	while (lst != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		if (prev == NULL)
			list = new;
		else
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (list);
}
