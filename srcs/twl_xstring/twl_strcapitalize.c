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

char	*twl_strcapitalize(char *str)
{
	int		i;
	int		prev_is_letter;

	if (!str)
		return (void *)0;
	prev_is_letter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
		{
			if (!prev_is_letter)
				str[i] = str[i] - 32;
			prev_is_letter = 1;
		}
		else
		{
			prev_is_letter = 0;
		}
		if (str[i] >= 48 && str[i] <= 57)
			prev_is_letter = 1;
		i++;
	}
	return (str);
}
