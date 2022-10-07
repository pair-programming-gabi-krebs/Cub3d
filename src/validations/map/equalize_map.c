/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:56:27 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/08 01:56:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	equalize_map(char **map)
{
	int		i;
	size_t	line_len;
	size_t	biggest_line;

	biggest_line = biggest_str(map);
	i = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len < biggest_line)
			strjoin_spaces(map, biggest_line, line_len, i);
		i++;
	}
}
