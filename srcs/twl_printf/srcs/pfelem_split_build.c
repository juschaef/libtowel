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

#include "twl_printf.h"

static char		*get_next_seg_from_raw(char *raw, char *charlist)
{
	char	*tmp;
	char	*out;
	int		i;

	i = 0;
	if (!raw)
		return (twl_strdup(""));
	if (charlist == NULL)
		return (twl_strdup(raw));
	tmp = twl_strnew(twl_strlen(raw));
	while (*raw && twl_strchr(charlist, *raw))
	{
		tmp[i] = *raw;
		raw++;
		i++;
	}
	out = twl_strdup(tmp);
	free(tmp);
	return (out);
}

void			pfelem_split_build(t_pfelem *pfelem)
{
	char	*raw;
	int		len;

	len = 1;
	raw = pfelem->raw;
	pfelem->split[SEG_FLAG] = get_next_seg_from_raw(raw + len, FLAGS_ALL);
	len += twl_strlen(pfelem->split[SEG_FLAG]);
	pfelem->split[SEG_MIN_WIDTH] = get_next_seg_from_raw(raw + len,
															MIN_WIDTH_ALL);
	len += twl_strlen(pfelem->split[SEG_MIN_WIDTH]);
	pfelem->split[SEG_PRECISION] = get_next_seg_from_raw(raw + len,
															PRECISION_ALL);
	len += twl_strlen(pfelem->split[SEG_PRECISION]);
	pfelem->split[SEG_LENGTH_MODIF] = get_next_seg_from_raw(raw + len,
															LEN_MOD_ALL);
	len += twl_strlen(pfelem->split[SEG_LENGTH_MODIF]);
	pfelem->split[SEG_CONV_SPEC] = get_next_seg_from_raw(raw + len, NULL);
}
