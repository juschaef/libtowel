/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strjoinarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/02/26 17:10:24 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <stdlib.h>
#include <twl_arr.h>
#include <twl_xstring.h>

char		*twl_strjoinarr(const char **arr, const char *sep)
{
	t_lst	*lst;
	char	*output;

	lst = twl_arr_to_lst(arr);
	output = twl_strjoinlst(lst, sep);
	twl_lst_del(lst, NULL);
	return (output);
}
