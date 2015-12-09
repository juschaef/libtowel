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

#include <stdlib.h>
#include "twl_opt_elem.h"
#include "twl_arr.h"
#include "twl_xstring.h"

void	twl_opt_elem_del(t_opt_elem *twl_opt_elem)
{
	free(twl_opt_elem->key);
	free(twl_opt_elem->value);
	free(twl_opt_elem);
}
