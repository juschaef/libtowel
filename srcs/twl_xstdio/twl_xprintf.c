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

#include <unistd.h>

#include "twl_stdio.h"
#include "twl_color.h"

#include "twl_printf.h"

void				twl_xprintf(const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	twl_dprintf(STDERR_FILENO, "%s[error] ", C_RED);
	pf_print_fd(pf, STDERR_FILENO);
	twl_dprintf(STDERR_FILENO, "%s\n", C_CLEAR);
	va_end(pf->arglist);
	len = pf->output_len;
	pf_free(pf);
	exit(1);
	(void)len;
}
