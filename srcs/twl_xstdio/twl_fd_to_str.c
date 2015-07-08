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
#include <fcntl.h>

#include "twl_string.h"
#include "twl_xstdio.h"

#define MAX_FILESIZE 2 * 1000 * 1000
#define BUFF_READ_SIZE 42

char				*twl_fd_to_str(int fd)
{
	char			buf[MAX_FILESIZE];
	char			*ptr;
	int				ret;

	twl_bzero(buf, MAX_FILESIZE);
	ptr = buf;
	while ((ret = read(fd, ptr, BUFF_READ_SIZE)) > 0)
	{
		ptr += ret;
		if ((ptr - buf) > (MAX_FILESIZE - BUFF_READ_SIZE - 1))
			twl_xprintf("[ERROR] Input too large\n");
	}
	if (ret == -1)
		twl_xprintf("[ERROR] Read error\n");
	return (twl_strdup(buf));
}