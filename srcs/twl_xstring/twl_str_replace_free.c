/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_str_replace_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 22:00:22 by yyang             #+#    #+#             */
/*   Updated: 2015/02/26 17:12:15 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_xstring.h"

char *twl_str_replace_free(char *s, char *target, char *replacement)
{
	char *replaced_str;

	replaced_str = twl_str_replace(s, target, replacement);
	twl_free(s);
	return (replaced_str);
}
