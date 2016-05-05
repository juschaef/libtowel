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

#include "twl_xunistd.h"
#include "twl_string.h"

int					twl_getch(void)
{
	char			buffer[4];
	int				key;

	key = 0;
	twl_bzero(buffer, 4);
	read(0, buffer, 4);
	key = buffer[0];
	key += buffer[1] << 8;
	key += buffer[2] << 16;
	return (key);
}
