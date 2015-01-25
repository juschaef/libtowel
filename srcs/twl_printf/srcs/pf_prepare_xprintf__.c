/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prepare_xprintf__.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/25 16:11:37 by yyang            ###   ########.fr       */
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
