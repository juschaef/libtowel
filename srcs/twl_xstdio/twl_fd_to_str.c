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

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "twl_string.h"
#include "twl_xstdio.h"
#include "twl_xstring.h"

#define BUFF_READ_SIZE 1024

char				*twl_fd_to_str(int fd)
{
	char			buf[BUFF_READ_SIZE + 1];
	char			*out;
	int				ret;

	out = twl_strdup("");
	while ((ret = read(fd, buf, BUFF_READ_SIZE)) > 0)
	{
		buf[ret] = '\0';
		out = twl_strjoinfree(out, buf, 'l');
	}
	if (ret == -1)
	{
		free(out);
		return (NULL);
	}
	return (out);
}
