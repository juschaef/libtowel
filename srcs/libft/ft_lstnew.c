/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:11:03 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 09:22:47 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list				*twl_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*mem;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->content = NULL;
	list->content_size = 0;
	if (content_size <= 0 || !content)
		return (list);
	mem = twl_memalloc(content_size);
	if (!mem)
		return (NULL);
	twl_memcpy(mem, content, content_size);
	list->content = mem;
	list->content_size = content_size;
	return (list);
}
