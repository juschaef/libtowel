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

#ifndef TWL_STDIO_H
# define TWL_STDIO_H

typedef struct		s_error_info
{
	int				value;
	char			*name;
	char			*msg;
}					t_error_info;

int					twl_printf(const char *fmt, ...);
int					twl_sprintf(char *out, const char *fmt, ...);
int					twl_asprintf(char **s, const char *fmt, ...);
int					twl_dprintf(const int fd, const char *fmt, ...);
int					twl_putchar(int c);

char				*twl_strerror(int errnum);

#endif
