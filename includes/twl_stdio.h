/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_stdio.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:29:56 by yyang             #+#    #+#             */
/*   Updated: 2015/01/31 11:48:37 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_STDIO_H
# define TWL_STDIO_H

int				twl_printf(const char *fmt, ...);
int				twl_asprintf(char **s, const char *fmt, ...);
int				twl_dprintf(const int fd, const char *fmt, ...);

#endif
