/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:45:21 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:39:12 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_lst.h"

t_lst	*twl_lst_new(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->head = NULL;
	return (lst);
}
