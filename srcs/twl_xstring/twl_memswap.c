/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:20:55 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:38:02 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"
#include "twl_xstring.h"

void	twl_memswap(void *s1, void *s2, size_t len)
{
	void *tmp;

	tmp = malloc(len);
	twl_memcpy(tmp, s1, len);
	twl_memcpy(s1, s2, len);
	twl_memcpy(s2, tmp, len);
	twl_free(tmp);
}
