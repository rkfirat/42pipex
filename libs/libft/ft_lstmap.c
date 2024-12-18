/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:37:48 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/20 14:34:41 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*i;
	void	*content;

	if (!lst || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		content = (f)(lst->content);
		i = ft_lstnew(content);
		if (!i)
		{
			del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, i);
		lst = lst->next;
		i = i->next;
	}
	return (result);
}
