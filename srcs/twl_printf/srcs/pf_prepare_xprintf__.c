/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prepare_xprintf__.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/30 16:09:15 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

char *pf_prepare_xprintf__(t_pf *pf)
{
	pf_build_pflist(pf);
	pf_iter_pfelem(pf);
	pf_add_arg_to_elem(pf);
	pf_concat(pf);
	return (pf->output);
}
