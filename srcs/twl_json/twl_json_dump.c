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

#include "twl_xstring.h"

#include "twl_json.h"

static void			concat_fn(void *token, void *output_str_)
{
	char			**output_str;

	output_str = output_str_;
	*output_str = twl_strjoinfree(*output_str, token, 'l');
}

char				*twl_json_dump(t_jnode *root_node)
{
	t_lst			*out;
	char			*output;

	out = twl_lst_new();
	twl_json_dump_rec(root_node, out);
	output = twl_strdup("");
	twl_lst_iter(out, concat_fn, &output);
	twl_lst_del(out, NULL);
	return output;
}
