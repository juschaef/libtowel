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
#include "twl_xstring.h"

char	*twl_strjoinfree(char *left, char *right, char free_num)
{
	char *out;

	out = twl_strjoin(left, right);
	if (free_num == 'b')
	{
		free(left);
		free(right);
	}
	else if (free_num == 'l')
		free(left);
	else if (free_num == 'r')
		free(right);
	return (out);
}
