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

#include "twl_printf.h"

void	pf_iter_pfelem(t_pf *pf)
{
	t_lst_elem__	*elem;
	t_pfelem		*pfelem;
	void			*conv_str_data;
	char			*dict_key;

	elem = pf->pflst->head;
	while (elem)
	{
		pfelem = elem->data;
		pfelem_split(pfelem);
		if (pfelem->conv_spec_str && *pfelem->conv_spec_str)
		{
			dict_key = twl_strjoin(pfelem->length_modifier_str,
														pfelem->conv_spec_str);
			conv_str_data = twl_dict_get(pf->conv_str_fns, dict_key);
			pfelem->conv_to_str = (conv_str_data) ? conv_str_data : NULL;
			free(dict_key);
		}
		else
			pfelem->conv_to_str = NULL;
		elem = elem->next;
	}
}
