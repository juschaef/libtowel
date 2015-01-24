/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 18:01:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 11:45:49 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <wchar.h>

size_t		twl_wstrlen(wchar_t *wstr)
{
	size_t len;

	len = 0;
	while (*wstr++)
		len++;
	return (len);
}
