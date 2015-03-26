/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 19:42:29 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:14:17 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_stdlib.h"
#include "twl_string.h"
#include "twl_xstring.h"

char	*twl_strjoinfree(char *left, char *right, char free_num)
{
	char *out;

	out = twl_strjoin(left, right);
	if (free_num == 'b')
	{
		twl_free(left);
		twl_free(right);
	}
	else if (free_num == 'l')
		twl_free(left);
	else if (free_num == 'r')
		twl_free(right);
	return (out);
}
