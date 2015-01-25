/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_arg_to_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/24 14:57:02 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>
#include <twl_arr.h>

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
	t_conv_val_fn conv_val_fn;

	if (i < (ac - 1))
	{
		conv_val_fn = twl_dict_get(pf->conv_val_fns, LST_CONV_SPEC_D);
		return (conv_val_fn(pf));
	}
	if (twl_strchr(CONV_SPEC_ALL, pfelem->conv_spec))
	{
		conv_val_fn = twl_dict_get(pf->conv_val_fns,
		twl_strjoin(pfelem->length_modifier_str, pfelem->conv_spec_str));
		return (conv_val_fn(pf));
	}
	return (NULL);
}

void			pf_add_arg_to_elem(t_pf *pf)
{
	t_twl_lst_elem	*elem;
	t_pfelem	*pfelem;
	int			i;
	int			ac;

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
		pfelem->values_count = i;
		pf_add_arg_c_handle_null_char(pfelem);
		elem = elem->next;
	}
}
