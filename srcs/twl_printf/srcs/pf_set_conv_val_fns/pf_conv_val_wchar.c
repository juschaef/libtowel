/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void	*pf_conv_val_wchar(t_pf *pf)
{
	wchar_t *intptr;

	intptr = malloc(sizeof(wchar_t) * 2);
	twl_bzero(intptr, sizeof(wchar_t) * 2);
	*intptr = (wchar_t)(va_arg(pf->arglist, wchar_t));
	return (intptr);
}
