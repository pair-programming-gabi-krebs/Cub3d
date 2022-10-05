/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_chars_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:00:54 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:01:24 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_valid_chars_line(char *s)
{
	int	i;
	
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != 49)
			return (0);
		i++;
	}
	return (1);
}
