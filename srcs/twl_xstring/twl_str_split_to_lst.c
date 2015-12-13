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
#include "twl_arr.h"
#include "twl_xstring.h"

t_lst				*twl_str_split_to_lst(char *str, char *chars)
{
	t_lst			*lst;
	char			**segs;

	segs = twl_strsplit_mul(str, chars);
	lst = twl_arr_to_lst(segs);
	twl_arr_del(segs, NULL);
	return (lst);
}
