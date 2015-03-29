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

#include <stdlib.h>
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
