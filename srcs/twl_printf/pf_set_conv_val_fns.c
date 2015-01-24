/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_val_fns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/13 16:26:28 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

static void		pf_set_conv_val_fns_simple(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_S, pf_conv_val_str);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_D, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_P, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_S_UP, pf_conv_val_wstr);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_D_UP, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_I, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_O, pf_conv_val_uint);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_O_UP, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_U, pf_conv_val_uint);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_U_UP, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_X, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_X_UP, pf_conv_val_int);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_C, pf_conv_val_char);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_C_UP, pf_conv_val_wchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_PERCENT, pf_conv_val_percent);
}

static void		pf_set_conv_val_fns_length_modif_high(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LD, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LI, pf_conv_val_long);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LU, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LO, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LX, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LX_UP, pf_conv_val_ulong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LC, pf_conv_val_wchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LS, pf_conv_val_wstr);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LLD, pf_conv_val_llong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LLI, pf_conv_val_llong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LLU, pf_conv_val_ullong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LLO, pf_conv_val_ullong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LLX, pf_conv_val_ullong);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_LLX_UP, pf_conv_val_ullong);
}

static void		pf_set_conv_val_fns_length_modif_low(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HD, pf_conv_val_short);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HI, pf_conv_val_short);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HU, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HO, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HX, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HX_UP, pf_conv_val_ushort);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HHD, pf_conv_val_char_hh);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HHI, pf_conv_val_char_hh);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HHU, pf_conv_val_uchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HHO, pf_conv_val_uchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HHX, pf_conv_val_uchar);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_HHX_UP, pf_conv_val_uchar);
}

static void		pf_set_conv_val_fns_float_double(t_pf *pf)
{
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_F, pf_conv_val_float);
	twl_dict_add(pf->conv_val_fns, LST_CONV_SPEC_F_UP, pf_conv_val_float);
}

void			pf_set_conv_val_fns(t_pf *pf)
{
	pf_set_conv_val_fns_simple(pf);
	pf_set_conv_val_fns_length_modif_high(pf);
	pf_set_conv_val_fns_length_modif_low(pf);
	pf_set_conv_val_fns_float_double(pf);
}
