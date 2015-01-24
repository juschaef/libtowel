/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 19:42:29 by yyang             #+#    #+#             */
/*   Updated: 2015/01/02 20:03:56 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *left, char *right, char free_num)
{
	char *out;

	out = ft_strjoin(left, right);
	if (free_num == 'b')
	{
		free(left);
		free(right);
	}
	else if (free_num == 'l')
		free(left);
	else if (free_num == 'r')
		free(right);
	return (out);
}
