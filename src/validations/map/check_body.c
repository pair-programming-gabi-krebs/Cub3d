/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:06:49 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/06 04:52:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"


static int	check_line(t_cube *cube, int i, char *line);
static void	equalize_map(char **map);

int	check_body(t_cube *cube)
{
	int		i;
	char	*line;

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

static int check_line(t_cube *cube, int i, char *line)
{
	int	j;

	j = 1;
	while (line[j])
	{
		if (line[j] == ' ')
		{
			if (cube->map.map[i] && (!check_valid_char(cube->map.map[i][j - 1])
				|| (cube->map.map[i] && !check_valid_char(cube->map.map[i][j + 1]))
				|| (cube->map.map[i + 1] && !check_valid_char(cube->map.map[i + 1][j]))
				|| (i > 0 && (cube->map.map[i - 1] && !check_valid_char(cube->map.map[i + 1][j])))))
				return (0);
		}
		j++;
	}
	return (1);
}

static void	equalize_map(char **map)
{
	int		i;
	size_t	line_len;
	size_t	biggest_line;
	char	*spaces;
	char	*aux;
	size_t	diff;

	i = 0;
	biggest_line = ft_strlen(map[i]);
	while (map[++i])
	{
		if (ft_strlen(map[i]) > biggest_line)
			biggest_line = ft_strlen(map[i]);	
	}
	i = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len < biggest_line)
		{
			diff = biggest_line - line_len;
			spaces = malloc(sizeof(char) * (diff));
			ft_memset(spaces, ' ', diff);
			map[i][line_len - 1] = ' ';
			aux = ft_strdup(map[i]);
			free(map[i]);
			map[i] = ft_strjoin(aux, spaces);
			free(aux);
			free(spaces);
		}
		printf("map[i]: %s'\n", map[i]);
		i++;
	}
}
