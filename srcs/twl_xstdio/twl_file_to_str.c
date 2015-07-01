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

#include "twl_xstdio.h"

char				*twl_file_to_str(char *file_name)
{
	int				fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		twl_xprintf("[ERROR] Can't open: %s\n", file_name);
	return (twl_fd_to_str(fd));
}
