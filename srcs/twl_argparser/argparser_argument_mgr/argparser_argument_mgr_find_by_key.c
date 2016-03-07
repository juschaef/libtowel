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

#include "twl_color.h"
#include "twl_argparser/argparser_argument_mgr.h"

t_argparser_argument	*argparser_argument_mgr_find_by_key(t_lst *arguments,
																	char *key)
{
	return (twl_lst_find(arguments, argparser_argument_test_by_key_void, key));
}
