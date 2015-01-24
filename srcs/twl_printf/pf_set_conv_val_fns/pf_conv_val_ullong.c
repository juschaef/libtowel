/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_val_ullong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:44:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:50:13 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void *pf_conv_val_ullong(t_pf *pf)
{
	unsigned long long *lptr;

	lptr = malloc(sizeof(unsigned long long));
	*lptr = va_arg(pf->arglist, unsigned long long);
	return (lptr);
}
