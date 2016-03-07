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

#include <stdlib.h>
#include "twl_xstdio.h"
#include "twl_argparser/argparser.h"

void				argparser_result_print_error_with_help(
													t_argparser_result *this)
{
	char			*help_str;

	help_str = argparser_get_help_str(this->argparser);
	if (this->err_msg)
	{
		twl_dprintf(2, "%s: %s\n", this->argparser->name, this->err_msg);
	}
	twl_putstr_fd(help_str, 2);
	free(help_str);
}
