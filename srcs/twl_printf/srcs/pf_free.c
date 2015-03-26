/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:12:23 by yyang             #+#    #+#             */
/*   Updated: 2015/01/31 16:21:48 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void	pf_free(t_pf *pf)
{
	twl_lst_del(pf->conv_str_fns, NULL);
	twl_lst_del(pf->conv_val_fns, NULL);
	twl_lst_del(pf->pflst, pfelem_free);
	twl_free(pf->output);
	twl_free(pf);
}
