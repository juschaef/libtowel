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

static void		pf_set_conv_val_fns_simple(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_S, pf_conv_val_str);
	twl_dict_add(pf->conv_val_fns, LST_CONV_D, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_P, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_S_UP, pf_conv_val_wstr);
	twl_dict_add(pf->conv_val_fns, LST_CONV_D_UP, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_I, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_O, pf_conv_val_uint);
	twl_dict_add(pf->conv_val_fns, LST_CONV_O_UP, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_U, pf_conv_val_uint);
	twl_dict_add(pf->conv_val_fns, LST_CONV_U_UP, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_X, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_X_UP, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_C, pf_conv_val_char);
	twl_dict_add(pf->conv_val_fns, LST_CONV_C_UP, pf_conv_val_wchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_PERCENT, pf_conv_val_percent);
}

static void		pf_set_conv_val_fns_length_modif_high(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_LD, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LI, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LU, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LO, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LX, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LX_UP, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LC, pf_conv_val_wchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LS, pf_conv_val_wstr);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LLD, pf_conv_val_llong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LLI, pf_conv_val_llong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LLU, pf_conv_val_ullong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LLO, pf_conv_val_ullong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LLX, pf_conv_val_ullong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_LLX_UP, pf_conv_val_ullong);
}

static void		pf_set_conv_val_fns_length_modif_low(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_HD, pf_conv_val_short);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HI, pf_conv_val_short);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HU, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HO, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HX, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HX_UP, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HHD, pf_conv_val_char_hh);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HHI, pf_conv_val_char_hh);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HHU, pf_conv_val_uchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HHO, pf_conv_val_uchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HHX, pf_conv_val_uchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_HHX_UP, pf_conv_val_uchar);
}

static void		pf_set_conv_val_fns_float_double(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_F, pf_conv_val_float);
	twl_dict_add(pf->conv_val_fns, LST_CONV_F_UP, pf_conv_val_float);
}

void			pf_set_conv_val_fns(t_pf *pf)
{
	pf_set_conv_val_fns_simple(pf);
	pf_set_conv_val_fns_length_modif_high(pf);
	pf_set_conv_val_fns_length_modif_low(pf);
	pf_set_conv_val_fns_float_double(pf);
}
