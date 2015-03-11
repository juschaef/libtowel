/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 16:08:05 by yyang             #+#    #+#             */
/*   Updated: 2015/03/11 20:00:07 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "twl_printf.h"

int			twl_lprintf(const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;
	int		fd;

	fd = open("debug.out", O_CREAT | O_WRONLY | O_APPEND);
	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	pf_print_fd(pf, fd);
	va_end(pf->arglist);
	len = pf->output_len;
	pf_free(pf);
	close(fd);
	return (len);
}
