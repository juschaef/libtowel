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

char	*twl_strchr(const char *s, int c)
{
	int		len;
	int		i;

	if (!s)
		return (void *)0;
	len = 0;
	while (s[len])
		len++;
	i = 0;
	while (i < len && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	return (void *)0;
}
