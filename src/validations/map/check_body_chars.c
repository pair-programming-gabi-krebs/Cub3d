/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 05:23:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/11/22 23:24:06 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

static int	check_valid_map_chars(char c);

void	check_body_chars(t_cube *cube)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (!check_valid_map_chars(cube->map.map[i][j]))
				ft_exit(cube, WRONG_CHAR);
			if (cube->map.map[i][j] == 'N' || cube->map.map[i][j] == 'S' \
				|| cube->map.map[i][j] == 'E' || cube->map.map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_exit(cube, WRONG_PLAYER);
}

static int	check_valid_map_chars(char c)
{
	char	*chs;
	int		i;
	int		match;

	chs = ft_strdup("01NWSE \n");
	i = 0;
	match = 0;
	while (chs[i])
	{
		if (chs[i] == c)
		{
			match = 1;
			break ;
		}
		i++;
	}
	free(chs);
	return (match);
}
