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

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "twl_xstdio.h"
#include "twl_printf.h"

int			twl_lprintf(const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;
	int		fd;

	fd = open(DEBUG_FILE_PATH, O_CREAT | O_WRONLY | O_APPEND, 0644);
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
