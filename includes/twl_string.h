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

#ifndef TWL_STRING_H
# define TWL_STRING_H

# include <stddef.h>

void				twl_bzero(void *s, size_t n);
void				*twl_memccpy(void *dst, const void *src, int c, size_t n);
void				*twl_memchr(const void *s, int c, size_t n);
int					twl_memcmp(const void *s1, const void *s2, size_t n);
void				*twl_memcpy(void *dst, const void *src, size_t n);
void				*twl_memmove(void *dst, const void *src, size_t n);
void				*twl_memdup(const void *s, size_t n);
void				*twl_memset(void *b, int c, size_t len);
char				*twl_strcat(char *s1, const char *s2);
char				*twl_strchr(const char *s, int c);
int					twl_strcmp(const char *s1, const char *s2);
char				*twl_strcpy(char *dst, const char *src);
char				*twl_strdup(const char *s1);
size_t				twl_strlcat(char *dst, const char *src, size_t size);
size_t				twl_strlen(const char *s);
char				*twl_strncat(char *s1, const char *s2, size_t n);
int					twl_strncmp(const char *s1, const char *s2, size_t n);
char				*twl_strncpy(char *dst, const char *src, size_t n);
char				*twl_strnstr(const char *s1, const char *s2, size_t n);
char				*twl_strrchr(const char *s, int c);
char				*twl_strstr(const char *s1, const char *s2);

#endif
