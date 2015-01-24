/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/12 23:13:21 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
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
