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
#include "twl_xstring.h"
#include "twl_xstdio.h"
#include "twl_printf.h"

int					twl_printf_escape_nl(const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;
	size_t	nl_count;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	nl_count = twl_strcountchar(pf->output, '\n');
	pf->output = twl_str_replace_free(pf->output, "\n", "\\n");
	pf->output_len += nl_count;
	pf_print_fd(pf, STDOUT_FILENO);
	va_end(pf->arglist);
	len = pf->output_len;
	pf_free(pf);
	return (len);
}
