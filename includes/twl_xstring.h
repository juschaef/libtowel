/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_xstring.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:05:35 by yyang             #+#    #+#             */
/*   Updated: 2015/03/11 11:10:34 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_XSTRING_H
# define TWL_XSTRING_H

# include <stddef.h>
# include "twl_lst.h"

# define FT_STRPAD_LEFT 'l'
# define FT_STRPAD_RIGHT 'r'

typedef struct	s_twl_strjoinarr_context
{
	char		*output;
	const char	*separator;
}				t_twl_strjoinarr_context;

char			*twl_itoa(int n);
char			*twl_ldtoa(long double ld);
char			*twl_lltoa(long long ln);
char			*twl_llutoa(unsigned long long ln);
char			*twl_llutobasestr(unsigned long long nbr, int base);
void			twl_memswap(void *s1, void *s2, size_t size);
void			twl_str_replace_char(char *s, char target, char replacement);
char			*twl_str_replace(char *s, char *target, char *replacement);
char			*twl_str_replace_free(char *s, char *target, char *replacement);
char			*twl_strcapitalize(char *str);
void			twl_strclr(char *s);
size_t			twl_strcountchar(char *s, char c);
void			twl_strdel(char **as);
int				twl_strequ(char const *s1, char const *s2);
void			twl_striter(char *s, void(*f)(char *));
void			twl_striteri(char *s, void(*f)(unsigned int, char *));
char			*twl_strjoin(char const *s1, char const *s2);
char			*twl_strjoinfree(char *left, char *right, char free_num);
char			*twl_strlowcase(char *str);
char			*twl_strmap(char const *s, char(*f)(char));
char			*twl_strmapi(char const *s, char(*f)(unsigned int, char));
int				twl_strnequ(char const *s1, char const *s2, size_t n);
char			*twl_strnew(size_t size);
char			*twl_strnewc(size_t size, char c);
char			*twl_strpad(const char *s, size_t min_width,
					char pad_dir, char c);
char			*twl_strrev(char *s);
char			**twl_strsplit(char const *s, char c);
char			**twl_strsplit_mul(char const *s, char *c);
char			*twl_strsub(char const *s, unsigned int start, size_t len);
void			twl_strswap(char **s1, char **s2);
char			*twl_strtrim(char const *s);
char			*twl_strtrimc(char const *s, char *chars);
char			*twl_strupcase(char *str);
char			*twl_wchar_to_str(wchar_t wstr);
char			*twl_wstr_to_str(wchar_t *wstr);
size_t			twl_wstrlen(wchar_t *wstr);
char			*twl_strjoinarr(const char **arr, const char *sep);
char			*twl_strjoinlst(t_lst *lst, const char *sep);
void			twl_add_char(char *s, char c);
#endif
