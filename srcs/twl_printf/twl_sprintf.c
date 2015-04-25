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

int			twl_sprintf(char *out, const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	va_end(pf->arglist);
	twl_memcpy(out, pf->output, pf->output_len);
	len = pf->output_len;
	pf_free(pf);
	return (len);
}
