/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/18 12:12:20 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char *pf_main(t_pf *pf)
{
	pf_build_pflist(pf);
	pf_iter_pfelem(pf);
	pf_add_arg_to_elem(pf);
	pf_concat(pf);
	return (pf->output);
}

int			ft_printf(const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_main(pf);
	pf_print(pf);
	va_end(pf->arglist);
	len = pf->output_len;
	pf_free(pf);
	return (len);
}

int			ft_asprintf(char **out, const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_main(pf);
	va_end(pf->arglist);
	*out = ft_strdup(pf->output);
	len = pf->output_len;
	pf_free(pf);
	return (len);
}
