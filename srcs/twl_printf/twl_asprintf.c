/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_asprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 16:07:57 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 16:13:30 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

int			twl_asprintf(char **out, const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	va_end(pf->arglist);
	*out = twl_strdup(pf->output);
	len = pf->output_len;
	pf_free(pf);
	return (len);
}
