/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:06:49 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 18:27:07 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

/* static int end_of_file(char **map); */

int	check_body(t_cube *cube)
{
	int		len;
	int		i;
	char	*line;

	i = 1;
	while (cube->map.map[i])
	{
		line = ft_strdup(cube->map.map[i]);
		len = ft_strlen(line) - 1;
		parse_line(&line);
		if ((!line[0] || !line[len - 1]) || (line[0] != '1' || \
			line[len - 1] != '1'))
		{
			free(line);
			return (0);
		}
		free(line);
		i++;
	}
	return (1);
}
