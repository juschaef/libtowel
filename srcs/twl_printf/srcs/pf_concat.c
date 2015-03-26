/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:59:28 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:03:47 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

static size_t	pf_printf_len(t_pfelem *pfelem)
{
	size_t len;

	if (pfelem->conv_spec == CONV_SPEC_C || pfelem->conv_spec == CONV_SPEC_C_UP)
	{
		if (pfelem->c_is_null_char)
		{
			len = pfelem->min_width;
			len = (len < 1) ? 1 : len;
			return (len);
		}
	}
	return (twl_strlen(pfelem->str));
}

static void		pf_clean_str(t_pfelem *pfelem, char *str)
{
	if (pfelem->conv_spec == CONV_SPEC_C || pfelem->conv_spec == CONV_SPEC_C_UP)
	{
		if (pfelem->c_is_null_char)
		{
			*(twl_strchr(str, REPLACEMENT_FOR_NULL_CHAR)) = '\0';
		}
	}
}

char			*pf_cat(t_pf *pf, t_pfelem *pfelem)
{
	char	*tmp;
	char	*str;
	size_t	len;

	str = twl_strdup(pfelem->str);
	len = pf_printf_len(pfelem);
	tmp = twl_memdup(pf->output, pf->output_len + len + 1);
	twl_free(pf->output);
	pf_clean_str(pfelem, str);
	twl_memcpy(tmp + pf->output_len, str, len);
	twl_free(str);
	tmp[pf->output_len + len] = '\0';
	return (tmp);
}

void			pf_concat(t_pf *pf)
{
	t_lst_elem__	*elem;
	t_pfelem		*pfelem;

	elem = pf->pflst->head;
	pf->output = twl_strnew(0);
	pf->output_len = 0;
	while (elem)
	{
		pfelem = elem->data;
		pfelem_convert_to_str(pfelem);
		pf->output = pf_cat(pf, pfelem);
		pf->output_len += pf_printf_len(pfelem);
		elem = elem->next;
	}
}
