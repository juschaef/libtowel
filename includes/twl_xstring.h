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

#ifndef TWL_XSTRING_H
# define TWL_XSTRING_H

# include <stddef.h>
# include "twl_lst.h"

# define FT_STRPAD_LEFT 'l'
# define FT_STRPAD_RIGHT 'r'

typedef struct		s_twl_strjoinarr_context
{
	char			*output;
	const char		*separator;
}					t_twl_strjoinarr_context;

char				*twl_itoa(int n);
char				*twl_ldtoa(long double ld);
char				*twl_lltoa(long long ln);
char				*twl_llutoa(unsigned long long ln);
char				*twl_llutobasestr(unsigned long long nbr, int base);
void				twl_memswap(void *s1, void *s2, size_t size);
void				twl_str_replace_char(char *s, char target,
															char replacement);
char				*twl_str_replace(char *s, char *target, char *replacement);
char				*twl_str_replace_free(char *s, char *target,
															char *replacement);
char				*twl_str_replace_first(char *s, char *old, char *new);
char				*twl_strcapitalize(char *str);
void				twl_strclr(char *s);
size_t				twl_strcountchar(char *s, char c);
void				twl_strdel(char **as);
int					twl_strequ(char const *s1, char const *s2);
bool				twl_strequ_void(void *s1, void *s2);
void				twl_striter(char *s, void(*f)(char *));
void				twl_striteri(char *s, void(*f)(unsigned int, char *));
char				*twl_strjoin(char const *s1, char const *s2);
char				*twl_strjoinfree(char *left, char *right, char free_num);
char				*twl_strlowcase(char *str);
char				*twl_strmap(char const *s, char(*f)(char));
char				*twl_strmapi(char const *s, char(*f)(unsigned int, char));
int					twl_strnequ(char const *s1, char const *s2, size_t n);
char				*twl_strnew(size_t size);
char				*twl_strnewc(size_t size, char c);
char				*twl_strpad(const char *s, size_t min_width,
														char pad_dir, char c);
char				*twl_strrev(char *s);
char				**twl_strsplit(char const *s, char c);
char				**twl_strsplit_mul(char const *s, char *c);
char				*twl_strsub(char const *s, unsigned int start, size_t len);
void				twl_strswap(char **s1, char **s2);
char				*twl_strtrim(char const *s);
char				*twl_strtrim_free(char *s);
char				*twl_strtrim_chars(char const *s, char *chars);
char				*twl_strtrim_chars_free(char *s, char *chars);
char				**twl_strsplit_mul_trim_chars(char const *s,
										char *split_chars, char *trim_chars);
char				*twl_strupcase(char *str);
char				*twl_wchar_to_str(wchar_t wstr);
char				*twl_wstr_to_str(wchar_t *wstr);
size_t				twl_wstrlen(wchar_t *wstr);
char				*twl_strjoinarr(const char **arr, const char *sep);
char				*twl_strjoinlst(t_lst *lst, const char *sep);
void				twl_add_char(char *s, char c);
char				**twl_str_to_av(char *str);
int					twl_str_starts_with(char *base, char *prefix);
bool				twl_str_ends_with(char *base, char *suffix);
unsigned int		twl_str_count_char(char *s, char c);
unsigned int		twl_str_ncount_char(char *s, char c, int n);
char				*twl_str_compress_char(char *s, char c);
bool				twl_str_contains_only(char *source, char *target);
bool				twl_str_is_int(char *s);
bool				twl_str_is_num(char *s);
bool				twl_str_is_pos_num(char *s);
char				*twl_str_split_get(char *str, char *split_chars, int index);
char				*twl_strchr_any(const char *haystack, const char *needles);
char				*twl_str_before_any_char(const char *src,
												const char *chars);
char				*twl_strndup(const char *src, int n);
int					twl_strpos(const char *str, char c);
char				*twl_strstr_last(const char *s1, const char *s2);
size_t				twl_strstr_count(const char *s1, const char *s2);
void				twl_str_print_xtimes(char *str, int times);

char				*twl_str_truncate(char *str, size_t len);
char				*twl_str_truncate_free(char *str, size_t len);

void				*twl_strdup_void(void *str);
char				*twl_strdup_or_null(const char *s);

/*
** lst
*/

t_lst				*twl_str_split_to_lst(char *str, char *chars);
t_lst				*twl_str_split_once_to_lst(char *str, char *chars);

#endif
