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
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LLU, pf_conv_str_ull);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LLO, pf_conv_str_octal_ull);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LLX, pf_conv_str_hex_ull);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LLX_UP, pf_conv_str_hex_ull_up);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HD, pf_conv_str_short);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HI, pf_conv_str_short);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HU, pf_conv_str_ushort);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HO, pf_conv_str_octal_us);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HX, pf_conv_str_hex_us);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HX_UP, pf_conv_str_hex_us_up);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HHD, pf_conv_str_char_hh);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HHI, pf_conv_str_char_hh);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HHU, pf_conv_str_uchar);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HHO, pf_conv_str_octal_uc);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HHX, pf_conv_str_hex_uc);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_HHX_UP, pf_conv_str_hex_uc_up);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_PERCENT,
												pf_conv_str_return_original);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_F, pf_conv_str_float);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_F_UP, pf_conv_str_float);
}

void			pf_set_conv_str_fns(t_pf *pf)
{
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_S, pf_conv_str_str);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_I, pf_conv_str_int);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_D, pf_conv_str_int);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_P, pf_conv_str_ptr);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_D_UP, pf_conv_str_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_S_UP, pf_conv_str_wstr);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_O, pf_conv_str_octal);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_O_UP, pf_conv_str_octal_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_U, pf_conv_str_unsign);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_U_UP, pf_conv_str_unsign_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_X, pf_conv_str_hex);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_X_UP, pf_conv_str_hex_up);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_C, pf_conv_str_char_c);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_C_UP, pf_conv_str_wchar);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LD, pf_conv_str_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LI, pf_conv_str_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LU, pf_conv_str_unsign_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LO, pf_conv_str_uoctal_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LX, pf_conv_str_hex_long);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LX_UP, pf_conv_str_hex_ul_up);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LC, pf_conv_str_wchar);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LS, pf_conv_str_wstr);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LLD, pf_conv_str_llong);
	ldict_add(pf->conv_str_fns, LST_CONV_SPEC_LLI, pf_conv_str_llong);
	pf_set_conv_str_fns_help(pf);
}
