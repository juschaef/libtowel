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

#define VOID_PTR_TO(type, value) *((type *)(value))

static char		*pf_conv_str_ptr(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(long, val), 16));
}

static char		*pf_conv_str_octal_uc(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(unsigned char, val), 8));
}

static void		pf_set_conv_str_fns_help(t_pf *pf)
{
	twl_dict_add(pf->conv_str_fns, LST_CONV_LLU, pf_conv_str_ull);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LLO, pf_conv_str_octal_ull);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LLX, pf_conv_str_hex_ull);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LLX_UP, pf_conv_str_hex_ull_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HD, pf_conv_str_short);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HI, pf_conv_str_short);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HU, pf_conv_str_ushort);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HO, pf_conv_str_octal_us);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HX, pf_conv_str_hex_us);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HX_UP, pf_conv_str_hex_us_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HHD, pf_conv_str_char_hh);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HHI, pf_conv_str_char_hh);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HHU, pf_conv_str_uchar);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HHO, pf_conv_str_octal_uc);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HHX, pf_conv_str_hex_uc);
	twl_dict_add(pf->conv_str_fns, LST_CONV_HHX_UP, pf_conv_str_hex_uc_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_PERCENT,
												pf_conv_str_return_original);
	twl_dict_add(pf->conv_str_fns, LST_CONV_F, pf_conv_str_float);
	twl_dict_add(pf->conv_str_fns, LST_CONV_F_UP, pf_conv_str_float);
}

void			pf_set_conv_str_fns(t_pf *pf)
{
	twl_dict_add(pf->conv_str_fns, LST_CONV_S, pf_conv_str_str);
	twl_dict_add(pf->conv_str_fns, LST_CONV_I, pf_conv_str_int);
	twl_dict_add(pf->conv_str_fns, LST_CONV_D, pf_conv_str_int);
	twl_dict_add(pf->conv_str_fns, LST_CONV_P, pf_conv_str_ptr);
	twl_dict_add(pf->conv_str_fns, LST_CONV_D_UP, pf_conv_str_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_S_UP, pf_conv_str_wstr);
	twl_dict_add(pf->conv_str_fns, LST_CONV_O, pf_conv_str_octal);
	twl_dict_add(pf->conv_str_fns, LST_CONV_O_UP, pf_conv_str_octal_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_U, pf_conv_str_unsign);
	twl_dict_add(pf->conv_str_fns, LST_CONV_U_UP, pf_conv_str_unsign_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_X, pf_conv_str_hex);
	twl_dict_add(pf->conv_str_fns, LST_CONV_X_UP, pf_conv_str_hex_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_C, pf_conv_str_char_c);
	twl_dict_add(pf->conv_str_fns, LST_CONV_C_UP, pf_conv_str_wchar);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LD, pf_conv_str_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LI, pf_conv_str_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LU, pf_conv_str_unsign_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LO, pf_conv_str_uoctal_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LX, pf_conv_str_hex_long);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LX_UP, pf_conv_str_hex_ul_up);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LC, pf_conv_str_wchar);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LS, pf_conv_str_wstr);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LLD, pf_conv_str_llong);
	twl_dict_add(pf->conv_str_fns, LST_CONV_LLI, pf_conv_str_llong);
	pf_set_conv_str_fns_help(pf);
}
