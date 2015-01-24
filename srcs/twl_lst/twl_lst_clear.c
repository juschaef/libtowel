/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 23:23:44 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/23 21:09:18 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <stdio.h> //

void	twl_lst_clear(t_lst *lst, void (*delfn)())
{
	twl_lst_iter_elem_(lst, (void *)twl_lstelem_del, delfn);
	lst->elems = NULL;
}
