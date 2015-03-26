/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/13 14:37:17 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_printf.h"

t_pf	*pf_create(char *fmt)
{
	t_pf *pf;

	pf = malloc(sizeof(t_pf));
	pf->fmt = fmt;
	pf->conv_val_fns = twl_lst_new();
	pf->conv_str_fns = twl_lst_new();
	pf_set_conv_val_fns(pf);
	pf_set_conv_str_fns(pf);
	pf->output_len = 0;
	return (pf);
}
