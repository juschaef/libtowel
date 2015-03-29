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
#include "twl_arr.h"

#include <stdio.h>

static int		pf_count_args(char *s)
{
	int i;

	if (twl_strequ(s, "%"))
		return (0);
	if (*s != '%')
		return (0);
	i = 1;
	while (*s)
	{
		if (*s == '*')
			i++;
		s++;
	}
	return (i);
}

static void		pf_add_arg_c_handle_null_char(t_pfelem *pfelem)
{
	char	*c_ptr;
	int		full_conv_spec;

	full_conv_spec = FULL_CONV_SPEC(pfelem->length_modifier, pfelem->conv_spec);
	if ((full_conv_spec == CONV_SPEC_C) || (full_conv_spec == CONV_SPEC_C_UP))
	{
		c_ptr = pfelem->values[pfelem->values_count - 1];
		if (*c_ptr == '\0')
		{
			pfelem->c_is_null_char = 1;
			*c_ptr = REPLACEMENT_FOR_NULL_CHAR;
		}
	}
}

static void		*pf_get_values(t_pf *pf, t_pfelem *pfelem, int i, int ac)
{
	t_conv_val_fn	conv_val_fn;
	char			*dict_key;

	if (i < (ac - 1))
	{
		conv_val_fn = twl_dict_get(pf->conv_val_fns, LST_CONV_D);
		return (conv_val_fn(pf));
	}
	if (twl_strchr(CONV_SPEC_ALL, pfelem->conv_spec))
	{
		dict_key = twl_strjoin(pfelem->length_modifier_str,
														pfelem->conv_spec_str);
		conv_val_fn = twl_dict_get(pf->conv_val_fns, dict_key);
		free(dict_key);
		return (conv_val_fn(pf));
	}
	return (NULL);
}

void			pf_add_arg_to_elem(t_pf *pf)
{
	t_lst_elem__	*elem;
	t_pfelem		*pfelem;
	int				i;
	int				ac;

	elem = pf->pflst->head;
	while (elem)
	{
		i = 0;
		pfelem = elem->data;
		ac = pf_count_args(pfelem->raw);
		while (i < ac)
		{
			pfelem->values[i] = pf_get_values(pf, pfelem, i, ac);
			i++;
		}
		pfelem->values[i] = NULL;
		pfelem->values_count = i;
		pf_add_arg_c_handle_null_char(pfelem);
		elem = elem->next;
	}
}
