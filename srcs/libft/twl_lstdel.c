/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:11:03 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 09:23:03 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				twl_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;
	t_list	*nextlist;

	if (!alst && !del)
		return ;
	lst = *alst;
	while (lst)
	{
		nextlist = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nextlist;
	}
	*alst = NULL;
}
