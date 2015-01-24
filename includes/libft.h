/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:05:51 by yyang             #+#    #+#             */
/*   Updated: 2015/01/21 22:49:02 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <ft_bool.h>

# define MAX_INT_LENGTH 13
# define INT_MAX 2147483647
# define INT_MIN -INT_MAX - 1
# define LONG_MAX 9223372036854775807L
# define LONG_MIN -LONG_MAX - 1L

# define FT_STRPAD_LEFT 0
# define FT_STRPAD_RIGHT 1
# ifdef DEBUG_ASSERT_ENABLED
#  define DEBUG_ASSERT(cond) ft_assert(cond);
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

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_strrev(char *s);
int					ft_isblank(int c);
char				*ft_strtrimc(char const *s, char c);
void				*ft_memdup(const void *s, size_t n);
char				*ft_strcapitalize(char *str);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_abs(int n);
size_t				ft_factorial(size_t n);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
void				ft_memswap(void *s1, void *s2, size_t size);
void				ft_swap(int *p1, int *p2);
void				ft_ptrswap(void *p1, void *p2);
void				*ft_realloc(void *ptr, size_t size);
void				ft_strswap(char **s1, char **s2);
void				ft_sort_array(char **tab, int size);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*ft_llutobasestr(unsigned long long nbr, int base);
char				*ft_lltoa(long long ln);
char				*ft_llutoa(unsigned long long ln);
char				*ft_wchar_to_str(wchar_t wstr);
size_t				ft_wstrlen(wchar_t *wstr);
char				*ft_wstr_to_str(wchar_t *wstr);
char				*ft_strpad(const char *s, size_t min_width,
						int pad_dir, char c);
char				*ft_strnewc(size_t size, char c);
char				*ft_strjoinfree(char *left, char *right, char free_num);
size_t				ft_strcountchar(char *s, char c);
void				ft_assert(int cond);
char				*ft_ldtoa(long double ld);

#endif
