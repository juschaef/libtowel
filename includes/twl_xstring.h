/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_xstring.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:05:35 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 19:43:59 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TWL_XSTRING_H
# define TWL_XSTRING_H
# include <stddef.h>

char				*twl_itoa(int n);
char				*twl_ldtoa(long double ld);
char				*twl_lltoa(long long ln);
char				*twl_llutoa(unsigned long long ln);
char				*twl_llutobasestr(unsigned long long nbr, int base);
void				twl_memswap(void *s1, void *s2, size_t size);
void	twl_str_replace_char(char *s, char target, char replacement);
char	*twl_str_replace(char *s, char *target, char *replacement);
char				*twl_strcapitalize(char *str);
void				twl_strclr(char *s);
size_t				twl_strcountchar(char *s, char c);
void				twl_strdel(char **as);
// twl_strequ.c
// twl_striter.c
// twl_striteri.c
// twl_strjoin.c
// twl_strjoinfree.c
// twl_strlowcase.c
// twl_strmap.c
// twl_strmapi.c
// twl_strnequ.c
// twl_strnew.c
// twl_strnewc.c
// twl_strpad.c
// twl_strrev.c
// twl_strsplit.c
// twl_strsub.c
// twl_strswap.c
// twl_strtrim.c
// twl_strtrimc.c
// twl_strupcase.c
// twl_wchar_to_str.c
// twl_wstr_to_str.c
// twl_wstrlen.c

#endif
