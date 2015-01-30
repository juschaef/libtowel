/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:05:35 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:25:18 by juschaef         ###   ########.fr       */
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
