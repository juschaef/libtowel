/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:05:51 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:45:22 by yyang            ###   ########.fr       */
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

# ifdef DEBUG_ASSERT_ENABLED
#  define DEBUG_ASSERT(cond) twl_assert(cond);
# else
#  define DEBUG_ASSERT(cond) ;
# endif


typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;


void				*twl_memmove(void *dest, const void *src, size_t len);
int					twl_atoi(const char *str);
int					twl_isalpha(int c);
int					twl_isalnum(int c);
int					twl_isascii(int c);
int					twl_isprint(int c);
int					twl_toupper(int c);
int					twl_tolower(int c);

void				*twl_memalloc(size_t size);
void				twl_memdel(void **ap);
void				twl_putchar(char c);
void				twl_putstr(char const *s);
void				twl_putendl(char const *s);
void				twl_putnbr(int n);
void				twl_putchar_fd(char c, int fd);
void				twl_putstr_fd(char const *s, int fd);
void				twl_putendl_fd(char const *s, int fd);
void				twl_putnbr_fd(int n, int fd);

int					twl_abs(int n);
size_t				twl_factorial(size_t n);
void				twl_swap(int *p1, int *p2);
void				twl_ptrswap(void *p1, void *p2);
void				*twl_realloc(void *ptr, size_t size);
void				twl_sort_array(char **tab, int size);

t_list				*twl_lstnew(void const *content, size_t content_size);
void				twl_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				twl_lstdel(t_list **alst, void (*del)(void*, size_t));
void				twl_lstadd(t_list **alst, t_list *new);
void				twl_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*twl_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				twl_assert(int cond);

#endif
