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

double				twl_sqrt(const double m)
{
	double			i;
	int				j;
	double			x1;
	double			x2;

	i = 0;
	while ((i * i) <= m)
		i += 0.1f;
	x1 = i;
	j = 0;
	while (j < 10)
	{
		x2 = m;
		x2 /= x1;
		x2 += x1;
		x2 /= 2;
		x1 = x2;
		j++;
	}
	return (x2);
}
