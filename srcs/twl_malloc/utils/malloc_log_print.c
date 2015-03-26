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
#include <sys/stat.h>
#include <sys/mman.h>

#include "twl_xstdio.h"
#include "twl_malloc/zone.h"
#include "twl_malloc/zone_mgr.h"
#include "twl_malloc/utils.h"

void				malloc_log_print(void)
{
	int				fd;
	char			c;
	int				ret;

	fd = open(".log", O_RDONLY);
	while ((ret = read(fd, &c, 1)) > 0)
	{
		write(1, &c, 1);
	}
	close(fd);
}
