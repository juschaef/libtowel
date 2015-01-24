/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:11:03 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 09:22:55 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst && !del)
		return ;
	free(*alst);
	del((*alst)->content, (*alst)->content_size);
	(*alst) = NULL;
}
