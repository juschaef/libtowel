/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_getopt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:43:29 by emaniez           #+#    #+#             */
/*   Updated: 2015/02/17 09:05:16 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_GETOPT_H
# define TWL_GETOPT_H

# include <twl_string.h>

int	twl_simple_getopt(const char **av, const char *optstr,
		char **optopt, int *optind);

#endif
