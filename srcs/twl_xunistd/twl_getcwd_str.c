/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_getcwd_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2015/04/03 19:17:58 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "twl_string.h"

#define PATH_MAX 100 * 1000

char				*twl_getcwd_str(void)
{
	char			cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	return (twl_strdup(cwd));
}
