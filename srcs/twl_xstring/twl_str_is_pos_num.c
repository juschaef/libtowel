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

#include "twl_ctype.h"
#include "twl_xstring.h"

bool				twl_str_is_pos_num(char *s)
{
	if (twl_strlen(s) == 0)
		return (false);
	while (twl_isdigit(*s))
		s++;
	if (*s == '\0')
		return (true);
	return (false);
}
