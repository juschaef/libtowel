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
#include "twl_string.h"
#include "twl_arr.h"
#include "twl_xstring.h"

char		*twl_strjoinarr(const char **arr, const char *sep)
{
	t_lst	*lst;
	char	*output;

	lst = twl_arr_to_lst(arr);
	output = twl_strjoinlst(lst, sep);
	twl_lst_del(lst, NULL);
	return (output);
}
