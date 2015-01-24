/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:00:26 by yyang             #+#    #+#             */
/*   Updated: 2015/01/19 19:07:21 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_replace_char(char *s, char target, char replacement)
{
	while (*s)
	{
		if (*s == target)
			*s = replacement;
		s++;
	}
}
