/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_str_replace_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:00:26 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:13:47 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	twl_str_replace_char(char *s, char target, char replacement)
{
	while (*s)
	{
		if (*s == target)
			*s = replacement;
		s++;
	}
}
