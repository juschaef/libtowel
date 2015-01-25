/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_str_fns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/13 16:26:52 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

#define VOID_PTR_TO(type, value) *((type *)(value))

void			*free_val(void *val, void *val_to_free)
{
	free(val_to_free);
	return (val);
}

static char		*pf_conv_str_ptr(void *val)
{
	return (free_val(twl_llutobasestr(VOID_PTR_TO(long, val), 16), val));
}

static char		*pf_conv_str_octal_uc(void *val)
{
	return (free_val(twl_llutobasestr(VOID_PTR_TO(unsigned char, val), 8), val));
}

static void		pf_set_conv_str_fns_help(t_pf *pf)
{
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LLU, pf_conv_str_ull);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LLO, pf_conv_str_octal_ull);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LLX, pf_conv_str_hex_ull);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LLX_UP, pf_conv_str_hex_ull_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HD, pf_conv_str_short);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HI, pf_conv_str_short);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HU, pf_conv_str_ushort);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HO, pf_conv_str_octal_us);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HX, pf_conv_str_hex_us);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HX_UP, pf_conv_str_hex_us_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HHD, pf_conv_str_char_hh);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HHI, pf_conv_str_char_hh);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HHU, pf_conv_str_uchar);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HHO, pf_conv_str_octal_uc);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HHX, pf_conv_str_hex_uc);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_HHX_UP, pf_conv_str_hex_uc_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_PERCENT,
												pf_conv_str_return_original);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_F, pf_conv_str_float);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_F_UP, pf_conv_str_float);
}

void			pf_set_conv_str_fns(t_pf *pf)
{
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_S, pf_conv_str_str);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_I, pf_conv_str_int);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_D, pf_conv_str_int);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_P, pf_conv_str_ptr);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_D_UP, pf_conv_str_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_S_UP, pf_conv_str_wstr);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_O, pf_conv_str_octal);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_O_UP, pf_conv_str_octal_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_U, pf_conv_str_unsign);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_U_UP, pf_conv_str_unsign_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_X, pf_conv_str_hex);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_X_UP, pf_conv_str_hex_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_C, pf_conv_str_char_c);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_C_UP, pf_conv_str_wchar);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LD, pf_conv_str_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LI, pf_conv_str_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LU, pf_conv_str_unsign_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LO, pf_conv_str_uoctal_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LX, pf_conv_str_hex_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LX_UP, pf_conv_str_hex_ul_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LC, pf_conv_str_wchar);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LS, pf_conv_str_wstr);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LLD, pf_conv_str_llong);
	twl_dict_add(pf->conv_str_fns, LST_CONV_SPEC_LLI, pf_conv_str_llong);
	pf_set_conv_str_fns_help(pf);
}
