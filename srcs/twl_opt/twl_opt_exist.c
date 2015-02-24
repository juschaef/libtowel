/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/24 18:21:17 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_opt.h>
#include <twl_dict.h>

t_bool twl_opt_exist(t_twl_opt *twl_opt, char *opt_key)
{
	return (twl_dict_key_exist(twl_opt->opts, opt_key));
}
