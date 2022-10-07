/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:58:48 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/08 01:59:30 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

size_t	biggest_str(char **map)
{
	size_t	str_len;
	int	i;

	i = 0;
	str_len = ft_strlen(map[i]);
	while (map[++i])
	{
		if (ft_strlen(map[i]) > str_len)
			str_len = ft_strlen(map[i]);
	}
	return (str_len);
}
