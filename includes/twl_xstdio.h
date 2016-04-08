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

#ifndef TWL_XSTDIO_H
# define TWL_XSTDIO_H

# define DEBUG_FILE_PATH "/tmp/.debug.out"
# define COUCOU twl_lprintf("@ %s %s (%d)\n", __FILE__, __FUNCTION__, __LINE__);

void				twl_putstr(char const *s);
void				twl_putstr_fd(char const *s, int fd);
void				twl_putnchar(int n, char c);
void				twl_putchar_fd(char c, int fd);
int					twl_putchar_tty(int c);
void				twl_putnstr_fd(char const *s, int n, int fd);
void				twl_putnbr(int n);
void				twl_putnbr_fd(int n, int fd);
int					twl_lprintf(const char *fmt, ...);
void				twl_xprintf(const char *fmt, ...);
int					twl_printf_escape_nl(const char *fmt, ...);
char				*twl_fd_to_str(int fd);
char				*twl_file_to_str(char *file_name);

#endif
