/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:11:03 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 09:23:31 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *maplst;
	t_list *mapfirst;
	t_list *temp;

	maplst = NULL;
	mapfirst = NULL;
	while (lst)
	{
		temp = f(lst);
		if (maplst)
		{
			maplst->next = ft_lstnew(NULL, 0);
			maplst = maplst->next;
		}
		else
			maplst = ft_lstnew(NULL, 0);
		maplst->content = temp->content;
		maplst->content_size = temp->content_size;
		if (!mapfirst)
			mapfirst = maplst;
		lst = lst->next;
	}
	return (mapfirst);
}
