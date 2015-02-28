/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_range_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:19:12 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 19:28:19 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void twl_range_iter(int start, int end, void (*iter_fn)(int i, void *context),
																void *context)
{
	while (start < end)
	{
		iter_fn(start, context);
		start++;
	}
}