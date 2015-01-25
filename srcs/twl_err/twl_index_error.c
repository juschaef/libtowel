/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_index_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 16:05:01 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 16:40:46 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>
#include <unistd.h>

void	twl_index_error(const char *err_msg)
{
	twl_dprintf(STDERR_FILENO, "IndexError: %s", err_msg);
}
