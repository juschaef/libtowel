/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_split_build.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:23:38 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char		*get_next_seg_from_raw(char *raw, char *charlist)
{
	char	out[10000];
	int		i;

	i = 0;
	if (!raw)
		return (ft_strdup(""));
	if (charlist == NULL)
		return (ft_strdup(raw));
	while (*raw && ft_strchr(charlist, *raw))
	{
		out[i] = *raw;
		raw++;
		i++;
	}
	out[i] = 0;
	return (ft_strdup(out));
}

void			pfelem_split_build(t_pfelem *pfelem)
{
	char	*raw;
	int		len;

	len = 1;
	raw = pfelem->raw;
	pfelem->split[SEG_FLAG] = get_next_seg_from_raw(raw + len, FLAGS_ALL);
	len += ft_strlen(pfelem->split[SEG_FLAG]);
	pfelem->split[SEG_MIN_WIDTH] = get_next_seg_from_raw(raw + len,
															MIN_WIDTH_ALL);
	len += ft_strlen(pfelem->split[SEG_MIN_WIDTH]);
	pfelem->split[SEG_PRECISION] = get_next_seg_from_raw(raw + len,
															PRECISION_ALL);
	len += ft_strlen(pfelem->split[SEG_PRECISION]);
	pfelem->split[SEG_LENGTH_MODIF] = get_next_seg_from_raw(raw + len,
															LEN_MOD_ALL);
	len += ft_strlen(pfelem->split[SEG_LENGTH_MODIF]);
	pfelem->split[SEG_CONV_SPEC] = get_next_seg_from_raw(raw + len, NULL);
}
