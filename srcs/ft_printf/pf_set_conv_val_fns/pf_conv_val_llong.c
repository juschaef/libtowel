/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_val_llong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:44:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:49:57 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void *pf_conv_val_llong(t_pf *pf)
{
	long long *lptr;

	lptr = malloc(sizeof(long long));
	*lptr = va_arg(pf->arglist, long long);
	return (lptr);
}
