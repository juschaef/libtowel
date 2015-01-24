/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:05:56 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

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
