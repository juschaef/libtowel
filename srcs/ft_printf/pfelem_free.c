/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:14:05 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 21:07:59 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

static void		free_splits(t_pfelem *pfelem)
{
	int i;

	i = 0;
	if (!pfelem_is_raw_string(pfelem))
	{
		while (i < 5)
		{
			free(pfelem->split[i]);
			i++;
		}
	}
}

static void		free_values(t_pfelem *elem)
{
	int i;

	i = 0;
	if (!pfelem_is_raw_string(elem))
	{
		while (i < elem->values_count)
		{
			free(elem->values[i]);
			i++;
		}
	}
}

void			pfelem_free(t_pfelem *elem)
{
	free(elem->str);
	free(elem->prefix);
	free_splits(elem);
	free(elem->raw);
	free(elem);
	(void)free_values;
}
