/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/02/17 18:02:37 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>
#include "twl_printf.h"

void	*twl_arr_filter(void *arr_, t_bool (*filter_fn)
			(void *data, void *context), void *context)
{
	return (twl_arr_filter_del(arr_, filter_fn, context, NULL));
}
