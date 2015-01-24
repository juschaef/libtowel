/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_val_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:44:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:47:24 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void *pf_conv_val_int(t_pf *pf)
{
	int *intptr;

	intptr = malloc(sizeof(int));
	*intptr = va_arg(pf->arglist, int);
	return (intptr);
}
