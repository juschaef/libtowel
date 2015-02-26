/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_str_replace_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 22:00:22 by yyang             #+#    #+#             */
/*   Updated: 2015/02/26 15:29:38 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_xstring.h>
#include <stdlib.h>

char *twl_str_replace_free(char *s, char *target, char *replacement)
{
	char *replaced_str;
	replaced_str = twl_str_replace(s, target, replacement);
	free(s);
	return (replaced_str);
}
