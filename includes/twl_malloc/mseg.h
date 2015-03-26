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

#ifndef MSEG_H
# define MSEG_H

# include <stddef.h>

# include "twl_lst.h"

typedef	struct		s_mseg
{
	void			*addr;
	size_t			size;
}					t_mseg;

t_mseg				*mseg_new(void *addr, size_t size);
void				mseg_del(t_mseg *mseg);
void				mseg_del_void(void *mseg);
void				*mseg_next_addr(t_mseg *mseg);

#endif
