/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_iter_pfelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/24 11:45:52 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void	pf_iter_pfelem(t_pf *pf)
{
	t_lst_elem	*elem;
	t_pfelem	*pfelem;
	void	*conv_str_data;

	elem = pf->pflst->elems;
	while (elem)
	{
		pfelem = elem->data;
		pfelem_split(pfelem);
		if (pfelem->conv_spec_str && *pfelem->conv_spec_str)
		{
			conv_str_data = ldict_get(pf->conv_str_fns,
			twl_strjoin(pfelem->length_modifier_str, pfelem->conv_spec_str));
			if (conv_str_data)
				pfelem->conv_to_str = conv_str_data;
			else
				pfelem->conv_to_str = NULL;
		}
		else
		{
			pfelem->conv_to_str = NULL;
		}
		elem = elem->next;
	}
}
