/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:05:51 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 19:43:57 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <twl_bool.h>

# define MAX_INT_LENGTH 13
# define INT_MAX 2147483647
# define INT_MIN -INT_MAX - 1
# define LONG_MAX 9223372036854775807L
# define LONG_MIN -LONG_MAX - 1L

# define FT_STRPAD_LEFT 0
# define FT_STRPAD_RIGHT 1
# ifdef DEBUG_ASSERT_ENABLED
#  define DEBUG_ASSERT(cond) twl_assert(cond);
# else
#  define DEBUG_ASSERT(cond) ;
# endif

# define FT_STRLEN_MAX_LEN 1 * 1000 * 1000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef bool (t_sort_cmp_fn)(void *item1, void *item2, void *context);

void				*twl_memset(void *b, int c, size_t len);
void				twl_bzero(void *s, size_t n);
void				*twl_memcpy(void *dst, const void *src, size_t n);
void				*twl_memccpy(void *dst, const void *src, int c, size_t n);
void				*twl_memmove(void *dest, const void *src, size_t len);
void				*twl_memchr(const void *s, int c, size_t n);
int					twl_memcmp(const void *s1, const void *s2, size_t n);
size_t				twl_strlen(const char *s);
char				*twl_strdup(const char *s1);
char				*twl_strcpy(char *dst, const char *src);
char				*twl_strncpy(char *dst, const char *src, size_t n);
char				*twl_strcat(char *s1, const char *s2);
char				*twl_strncat(char *s1, const char *s2, size_t n);
size_t				twl_strlcat(char *dst, const char *src, size_t size);
char				*twl_strchr(const char *s, int c);
char				*twl_strrchr(const char *s, int c);
char				*twl_strstr(const char *s1, const char *s2);
char				*twl_strnstr(const char *s1, const char *s2, size_t n);
int					twl_strcmp(const char *s1, const char *s2);
int					twl_strncmp(const char *s1, const char *s2, size_t n);
int					twl_atoi(const char *str);
int					twl_isalpha(int c);
int					twl_isdigit(int c);
int					twl_isalnum(int c);
int					twl_isascii(int c);
int					twl_isprint(int c);
int					twl_toupper(int c);
int					twl_tolower(int c);

void				*twl_memalloc(size_t size);
void				twl_memdel(void **ap);
char				*twl_strnew(size_t size);
void				twl_striter(char *s, void(*f)(char *));
void				twl_striteri(char *s, void(*f)(unsigned int, char *));
char				*twl_strmap(char const *s, char(*f)(char));
char				*twl_strmapi(char const *s, char(*f)(unsigned int, char));
int					twl_strequ(char const *s1, char const *s2);
int					twl_strnequ(char const *s1, char const *s2, size_t n);
char				*twl_strsub(char const *s, unsigned int start, size_t len);
char				*twl_strjoin(char const *s1, char const *s2);
char				*twl_strtrim(char const *s);
char				**twl_strsplit(char const *s, char c);
void				twl_putchar(char c);
void				twl_putstr(char const *s);
void				twl_putendl(char const *s);
void				twl_putnbr(int n);
void				twl_putchar_fd(char c, int fd);
void				twl_putstr_fd(char const *s, int fd);
void				twl_putendl_fd(char const *s, int fd);
void				twl_putnbr_fd(int n, int fd);

char				*twl_strrev(char *s);
int					twl_isblank(int c);
char				*twl_strtrimc(char const *s, char c);
void				*twl_memdup(const void *s, size_t n);
int					twl_islower(int c);
int					twl_isupper(int c);
int					twl_ispunct(int c);
int					twl_isspace(int c);
int					twl_abs(int n);
size_t				twl_factorial(size_t n);
char				*twl_strupcase(char *str);
char				*twl_strlowcase(char *str);
void				twl_swap(int *p1, int *p2);
void				twl_ptrswap(void *p1, void *p2);
void				*twl_realloc(void *ptr, size_t size);
void				twl_strswap(char **s1, char **s2);
void				twl_sort_array(char **tab, int size);

t_list				*twl_lstnew(void const *content, size_t content_size);
void				twl_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				twl_lstdel(t_list **alst, void (*del)(void*, size_t));
void				twl_lstadd(t_list **alst, t_list *new);
void				twl_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*twl_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*twl_wchar_to_str(wchar_t wstr);
size_t				twl_wstrlen(wchar_t *wstr);
char				*twl_wstr_to_str(wchar_t *wstr);
char				*twl_strpad(const char *s, size_t min_width,
						int pad_dir, char c);
char				*twl_strnewc(size_t size, char c);
char				*twl_strjoinfree(char *left, char *right, char free_num);
void				twl_assert(int cond);

#endif
