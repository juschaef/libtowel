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
#include <unistd.h>
#include <time.h>

#include "twl_printf.h"
#include "twl_logger.h"
#include "twl_stdio.h"
#include "twl_xstdio.h"
#include "twl_color.h"
#include "twl_xstdio.h"

static char			*get_level_color(t_logger_level level)
{
	if (level == LOGGER_LEVEL_DEBUG)
		return ("\033[36;1mDEBUG");
	else if (level == LOGGER_LEVEL_INFO)
		return ("\033[32;1mINFO-");
	else if (level == LOGGER_LEVEL_WARN)
		return ("\033[33;1mWARN-");
	else if (level == LOGGER_LEVEL_ERROR)
		return ("\033[31;1mERROR");
	return ("UNKWON");
}

void				twl_logger_printf(t_logger_level level, const char *fn,
												int line, const char *fmt, ...)
{
	t_pf			*pf;
	int				fd;
	time_t			timer;
	char			time_buffer[26];
	struct tm		*tm_info;

	time(&timer);
	tm_info = localtime(&timer);
	strftime(time_buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
	if ((fd = open(DEBUG_FILE_PATH, O_CREAT | O_WRONLY | O_APPEND, 0644)) < 0)
	{
		twl_dprintf(2, "open error");
		exit(1);
	}
	pf = pf_create((char *)fmt);
	twl_dprintf(fd, "%s [%d] %s%s [%s:%d] ", time_buffer, getpid(),
		get_level_color(level), C_CLEAR, fn, line);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	pf_print_fd(pf, fd);
	twl_dprintf(fd, "\n");
	va_end(pf->arglist);
	pf_free(pf);
	close(fd);
}
