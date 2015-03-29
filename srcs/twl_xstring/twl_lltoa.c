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
#include "twl_xstring.h"

char	*twl_lltoa(long long ln)
{
	int		is_neg;
	char	*out;
	char	*tmp;

	is_neg = 0;
	if (ln < 0)
	{
		is_neg = 1;
		ln = -ln;
	}
	out = twl_llutoa(ln);
	if (is_neg)
	{
		tmp = out;
		out = twl_strjoin("-", out);
		free(tmp);
	}
	return (out);
}
