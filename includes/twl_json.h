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

#ifndef TWL_JSON_H
# define TWL_JSON_H

# include "twl_jnode.h"

# define JSON_STR_SEP ","
# define JSON_STR_NULL "null"
# define JSON_PRIM_START_CHARS "-0123456789tfn"

t_jnode				*twl_json_parse(char *json_str);
char				*twl_json_dump(t_jnode *json);
void				twl_json_dump_rec(t_jnode *node, t_lst *output);

#endif
