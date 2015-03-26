/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_val_wchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:44:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:50:23 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void *pf_conv_val_wchar(t_pf *pf)
{
	wchar_t *intptr;

	intptr = twl_malloc(sizeof(wchar_t) * 2);
	twl_bzero(intptr, sizeof(wchar_t) * 2);
	*intptr = (wchar_t)(va_arg(pf->arglist, wchar_t));
	return (intptr);
}
