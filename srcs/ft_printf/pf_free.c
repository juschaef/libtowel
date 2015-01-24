/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:12:23 by yyang             #+#    #+#             */
/*   Updated: 2015/01/13 16:21:57 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void	voidfn(void *fn)
{
	(void)fn;
}

void	pf_free(t_pf *pf)
{
	lst_del(pf->pflst, pfelem_free);
	lst_del(pf->conv_val_fns, voidfn);
	lst_del(pf->conv_str_fns, voidfn);
	free(pf->output);
	free(pf);
}
