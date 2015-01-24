/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_build_pflist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/23 16:46:58 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void pf_build_pflist(t_pf *pf)
{
	t_lst *fmt_list;

	fmt_list = pf_split(pf->fmt);
	pf->pflst = lst_map(fmt_list, pfelem_str2pfelem);
	lst_del(fmt_list, free);
}
