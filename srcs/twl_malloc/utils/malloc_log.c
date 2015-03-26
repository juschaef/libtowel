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

#include "twl_xstdio.h"
#include "twl_malloc/zone.h"
#include "twl_malloc/zone_mgr.h"
#include "twl_malloc/utils.h"

void				malloc_log(t_zone_mgr *zone_mgr, void *addr)
{
	int				fd;
	t_mseg			*mseg;

	fd = open(".log", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		return ;
	mseg = zone_mgr_get_mseg_by_addr(zone_mgr, addr);
	twl_putstr_fd("0x", fd);
	twl_llutobasestr_print_fd((unsigned long long)addr, 16, fd);
	twl_putstr_fd("\t", fd);
	twl_putstr_fd(zone_mgr->name, fd);
	if (mseg)
	{
		twl_putstr_fd("\t", fd);
		twl_putnbr_size_t_fd(mseg->size, fd);
		twl_putstr_fd(" bytes", fd);
	}
	twl_putstr_fd("\n", fd);
	close(fd);
}
