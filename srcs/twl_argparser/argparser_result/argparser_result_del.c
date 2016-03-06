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
#include "twl_argparser/argparser_result.h"

void				argparser_result_del(t_argparser_result *this)
{
	twl_lst_del(this->result_items, argparser_result_item_del_void);
	twl_lst_del(this->remainders, free);
	if (this->err_msg)
		free(this->err_msg);
	free(this->command_name);
	free(this);
}
