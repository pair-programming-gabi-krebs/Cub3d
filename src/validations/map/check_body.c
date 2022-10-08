/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:06:49 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/08 04:21:42 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

static void check_body_chars(t_cube *cube);

int	check_body(t_cube *cube)
{
	int		i;
	char	*line;

	check_body_chars(cube);
	equalize_map(cube->map.map);
	i = 0;
	while (cube->map.map[i])
	{
		line = ft_strdup(cube->map.map[i]);
		parse_line(&line);
		if (check_border_line(line) || !check_line(cube, i, cube->map.map[i]))
			return (0);
		free(line);
		i++;
	}
	return (1);
}

static void	check_body_chars(t_cube *cube)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while(cube->map.map[i][j])
		{
/* 			if (!check_valid_char(cube->map.map[i][j]))
				ft_exit(cube, WRONG_CHAR); */
			if (cube->map.map[i][j] == 'N' || cube->map.map[i][j] == 'S' \
				|| cube->map.map[i][j] == 'E' || cube->map.map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	printf("player: %d", player);
	if (player != 1)
		ft_exit(cube, WRONG_PLAYER);
}