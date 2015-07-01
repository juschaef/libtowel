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

char				*twl_file_to_str(char *file_name)
{
	char			buf[MAX_FILESIZE];
	char			*ptr;
	int				ret;
	int				fd;

	twl_bzero(buf, MAX_FILESIZE);
	ptr = buf;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		twl_xprintf("[ERROR] Can't open: %s\n", file_name);
	while ((ret = read(fd, ptr, BUFF_READ_SIZE)) > 0)
	{
		ptr += ret;
		if ((ptr - buf) > (MAX_FILESIZE - BUFF_READ_SIZE - 1))
			twl_xprintf("[ERROR] File too large: %s\n", file_name);
	}
	if (ret == -1)
		twl_xprintf("[ERROR] Read error: %s\n", file_name);
	return (twl_strdup(buf));
}
