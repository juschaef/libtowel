/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:23:37 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/30 15:16:36 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_PRINTF_H
# define TWL_PRINTF_H

# include <twl_lst.h>
# include <twl_dict.h>
# include <twl_printf_elem.h>
# include <twl_xstring.h>
# include <twl_string.h>
# include <twl_ctype.h>
# include <twl_stdlib.h>

# include <stdarg.h>
# include <stdlib.h>

# define MAX_FNS 1000000000
# define CONV_ERROR_MSG "(conversion error)"

/*
** API
*/

int				twl_printf(const char *fmt, ...);
int				twl_asprintf(char **s, const char *fmt, ...);
int				twl_dprintf(const int fd, const char *fmt, ...);

/*
** Internals
*/

typedef struct	s_pf
{
	t_lst		*pflst;
	char		*fmt;
	char		*output;
	size_t		output_len;
	va_list		arglist;
	t_lst		*conv_val_fns;
	t_lst		*conv_str_fns;
}				t_pf;

typedef void	*(*t_conv_val_fn) (t_pf *pf);
typedef char	*(*t_conv_str_fn) (void *);

char			*pf_prepare_xprintf__(t_pf *pf);

t_pf			*pf_create(char *fmt);
t_lst			*pf_split(char *s);
void			pf_print_fd(t_pf *pf, int fd);
void			pf_concat(t_pf *pf);
void			pf_iter_pfelem(t_pf *pf);
void			pf_build_pflist(t_pf *pf);
void			pf_add_arg_to_elem(t_pf *pf);
void			pf_set_conv_val_fns(t_pf *pf);
void			pf_set_conv_str_fns(t_pf *pf);
void			pf_free(t_pf *pf);

void			*pf_conv_val_int(t_pf *pf);
void			*pf_conv_val_short(t_pf *pf);
void			*pf_conv_val_ushort(t_pf *pf);
void			*pf_conv_val_char(t_pf *pf);
void			*pf_conv_val_char_hh(t_pf *pf);
void			*pf_conv_val_uchar(t_pf *pf);
void			*pf_conv_val_long(t_pf *pf);
void			*pf_conv_val_llong(t_pf *pf);
void			*pf_conv_val_uint(t_pf *pf);
void			*pf_conv_val_ulong(t_pf *pf);
void			*pf_conv_val_ullong(t_pf *pf);
void			*pf_conv_val_wstr(t_pf *pf);
void			*pf_conv_val_wchar(t_pf *pf);
void			*pf_conv_val_str(t_pf *pf);
void			*pf_conv_val_percent(t_pf *pf);
void			*pf_conv_val_float(t_pf *pf);

char			*pf_conv_str_llong(void *val);
char			*pf_conv_str_octal_ull(void *val);
char			*pf_conv_str_ull(void *val);
char			*pf_conv_str_hex_ull(void *val);
char			*pf_conv_str_hex_ull_up(void *val);
char			*pf_conv_str_long(void *val);
char			*pf_conv_str_octal_long(void *val);
char			*pf_conv_str_uoctal_long(void *val);
char			*pf_conv_str_unsign_long(void *val);
char			*pf_conv_str_hex_long(void *val);
char			*pf_conv_str_int(void *val);
char			*pf_conv_str_short(void *val);
char			*pf_conv_str_ushort(void *val);
char			*pf_conv_str_octal_us(void *val);
char			*pf_conv_str_octal(void *val);
char			*pf_conv_str_str(void *val);
char			*pf_conv_str_char_c(void *val);
char			*pf_conv_str_char_hh(void *val);
char			*pf_conv_str_uchar(void *val);
char			*pf_conv_str_return_original(void *val);
char			*pf_conv_str_hex_uc(void *val);
char			*pf_conv_str_hex_us(void *val);
char			*pf_conv_str_hex(void *val);
char			*pf_conv_str_hex_uc_up(void *val);
char			*pf_conv_str_hex_us_up(void *val);
char			*pf_conv_str_wstr(void *val);
char			*pf_conv_str_wchar(void *val);
char			*pf_conv_str_hex_up(void *val);
char			*pf_conv_str_hex_ul_up(void *val);
char			*pf_conv_str_unsign(void *val);
char			*pf_conv_str_float(void *val);
void			*free_val(void *val, void *val_to_free);

#endif
