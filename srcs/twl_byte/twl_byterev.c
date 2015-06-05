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

void				twl_byterev(void *ptr_, int len)
{
	int				j;
	int				i;
	unsigned char	a;
	unsigned char	*ptr;

	ptr = ptr_;
	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = a;
		i++;
		j--;
	}
}
