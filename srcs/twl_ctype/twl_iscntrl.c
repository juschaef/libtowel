/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 42:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				twl_iscntrl(int c)
{
	if ((c >= 0 && c <= 037) || c == 0177)
		return (1);
	return (0);
}
