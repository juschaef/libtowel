/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 20:05:46 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:12:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"

size_t	twl_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
